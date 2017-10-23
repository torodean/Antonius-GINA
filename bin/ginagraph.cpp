//==========================================================================
// GINA (Generations of Implanted Nuclear Activity)
// Michigan State University - National Superconducting Cylotron Laboratory
// File: ginagraph.cpp
// Created By: Antonius Torode
// File Created: June 23, 2017
// Purpose: This file contains the graph utility of the GINA program.
//          This file is adapted from the Qt chart themes example file (see copywrite info below)
//==========================================================================


/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the Qt Charts module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:GPL$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3 or (at your option) any later version
** approved by the KDE Free Qt Foundation. The licenses are as published by
** the Free Software Foundation and appearing in the file LICENSE.GPL3
** included in the packaging of this file. Please review the following
** information to ensure the GNU General Public License requirements will
** be met: https://www.gnu.org/licenses/gpl-3.0.html.
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include "ginagraph.h"
#include <QApplication>
#include <QDesktopWidget>
#include <QtCharts/QChartView>
#include <QtCharts/QAbstractBarSeries>
#include <QtCharts/QPercentBarSeries>
#include <QtCharts/QStackedBarSeries>
#include <QtCharts/QLineSeries>
#include <QtCharts/QAreaSeries>
#include <QtCharts/QLegend>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtCore/QTime>
#include <QtCharts/QBarCategoryAxis>
#include <QColor>
#include <QMenuBar>
#include <QValueAxis>
#include <QPixmap>
#include <QDir>
#include "gina.h"

GinaGraph::GinaGraph(std::vector< std::vector<double>> xDatN, std::vector< std::vector<double>> xDatD,
                     std::vector< std::vector<double>> xDatCLH, std::vector<double> yDat,
                     std::int8_t xTicks, std::int8_t yTicks, QString process, QWidget *parent) :
    QWidget(parent),

    m_DataN(xDatN),  m_DataD(xDatD), m_DataCLH(xDatCLH), m_tData(yDat),
    m_xTicks(xTicks), m_yTicks(yTicks), m_process(process),
    m_saveButton(new QPushButton()),
    m_themeComboBox(createThemeBox()), m_antialiasCheckBox(new QCheckBox("Anti-aliasing")),
    m_animatedComboBox(createAnimationBox()), m_legendComboBox(createLegendBox()), chartPath("Images")
{
    connectSignals();

    m_process.remove(' ');
    // create layout
    QGridLayout *baseLayout = new QGridLayout();
    QHBoxLayout *settingsLayout = new QHBoxLayout();
    settingsLayout->addWidget(m_saveButton);
    settingsLayout->addWidget(new QLabel("Theme:"));
    settingsLayout->addWidget(m_themeComboBox);
    settingsLayout->addWidget(new QLabel("Animation:"));
    settingsLayout->addWidget(m_animatedComboBox);
    settingsLayout->addWidget(new QLabel("Legend:"));
    settingsLayout->addWidget(m_legendComboBox);
    settingsLayout->addWidget(m_antialiasCheckBox);
    settingsLayout->addStretch();
    baseLayout->addLayout(settingsLayout, 0, 0, 1, 3);

    QMenuBar *menu_bar = createMenuBar();
    baseLayout->addWidget(menu_bar);

    //create charts
    chartViewN = new QChartView(createLineChart(m_DataN,m_tData,"Nuclei Count", "N"));
    baseLayout->addWidget(chartViewN, 1, 0);
    m_charts << chartViewN;

    chartViewD = new QChartView(createLineChart(m_DataD,m_tData, "Decay Rates", "D"));
    baseLayout->addWidget(chartViewD, 1, 1);
    m_charts << chartViewD;

    chartViewCLH = new QChartView(createLineChart(m_DataCLH, m_tData, "Contamination", "CLH"));
    baseLayout->addWidget(chartViewCLH, 1, 2);
    m_charts << chartViewCLH;

    setLayout(baseLayout);

    if(!QDir(QDir::currentPath() + "/" + chartPath).exists()){
        QDir().mkdir(QDir::currentPath() + "/" + chartPath);
    }

    // Set defaults
    m_antialiasCheckBox->setChecked(true);
    m_saveButton->setText("Save Graphs");
    updateUI();
}

//Deconstructor for the GinaGraph class.
GinaGraph::~GinaGraph(){

}

//Creates actions for menu bar usage.
void GinaGraph::createActions(){
    //creates the File Menu Exit action.
    exitAction = new QAction(tr("E&xit"), this);
    exitAction->setShortcuts(QKeySequence::Quit);
    exitAction->setStatusTip(tr("Exit the application."));
    connect(exitAction, &QAction::triggered, this, &QWidget::close);

    saveAction = new QAction(tr("S&ave"), this);
    saveAction->setShortcuts(QKeySequence::Save);
    saveAction->setStatusTip(tr("Save the charts."));
    connect(saveAction, &QAction::triggered, this, &GinaGraph::saveChart);
}

//Saves the charts as PNG images.
bool GinaGraph::saveChart(){
    QPixmap N( chartViewN->size() );
    chartViewN->QWidget::render( &N );
    QString fileN = "N " + m_process + ".png";
    N.save(chartPath + "/" + fileN, "PNG");

    QPixmap D( chartViewN->size() );
    chartViewD->QWidget::render( &D );
    QString fileD = "D " + m_process + ".png";
    D.save(chartPath + "/" + fileD, "PNG");

    QPixmap CLH( chartViewN->size() );
    chartViewCLH->QWidget::render( &CLH );
    QString fileCLH = "CLH " + m_process + ".png";
    CLH.save(chartPath + "/" + fileCLH, "PNG");

    QWidget *widget = new QWidget();
    QLabel *label = new QLabel(widget);
    label->setText("Files saved to " +  QDir::currentPath() + "/Images/\n 3 files total:\n\t" + fileN + "\n\t" + fileD + "\n\t" + fileCLH);
    widget->resize(500, 100);

    //centers the widget
    QSize size;
    size = widget->size();
    QDesktopWidget *d = QApplication::desktop();
    int w = d->width();   // returns screen width
    int h = d->height();  // returns screen height
    int mw = size.width();
    int mh = size.height();
    int cw = (w/2) - (mw/2);
    int ch = (h/2) - (mh/2);
    widget->move(cw,ch);

    widget->show();

    return false;
}

void GinaGraph::saveCharts(){
    QPixmap N( chartViewN->size() );
    chartViewN->QWidget::render( &N );
    QString fileN = "N " + m_process + ".png";
    N.save("Images/" + fileN, "PNG");

    QPixmap D( chartViewN->size() );
    chartViewD->QWidget::render( &D );
    QString fileD = "D " + m_process + ".png";
    D.save("Images/" + fileD, "PNG");

    QPixmap CLH( chartViewN->size() );
    chartViewCLH->QWidget::render( &CLH );
    QString fileCLH = "CLH " + m_process + ".png";
    CLH.save("Images/" + fileCLH, "PNG");

    QWidget *widget = new QWidget();
    QLabel *label = new QLabel(widget);
    label->setText("Files saved to " +  QDir::currentPath() + "/Images/\n 3 files total:\n\t" + fileN + "\n\t" + fileD + "\n\t" + fileCLH);
    widget->resize(500, 100);

    //centers the widget
    QSize size;
    size = widget->size();
    QDesktopWidget *d = QApplication::desktop();
    int w = d->width();   // returns screen width
    int h = d->height();  // returns screen height
    int mw = size.width();
    int mh = size.height();
    int cw = (w/2) - (mw/2);
    int ch = (h/2) - (mh/2);
    widget->move(cw,ch);

    widget->show();
}

//Creates a menu bar for the graph windows that appear.
QMenuBar *GinaGraph::createMenuBar(){
    createActions();
    QMenuBar *menu_bar = new QMenuBar();
    QMenu* menu_File = menu_bar->addMenu( "File" );

    menu_File->addAction(exitAction);
    menu_File->addAction(saveAction);

    return menu_bar;
}

void GinaGraph::connectSignals(){
    connect(m_saveButton, SIGNAL(released()), this, SLOT(saveCharts()));
    connect(m_themeComboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(updateUI()));
    connect(m_antialiasCheckBox, SIGNAL(toggled(bool)), this, SLOT(updateUI()));
    connect(m_animatedComboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(updateUI()));
    connect(m_legendComboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(updateUI()));
}

QComboBox *GinaGraph::createThemeBox() const{
    // settings layout
    QComboBox *themeComboBox = new QComboBox();
    themeComboBox->addItem("Blue Cerulean", QChart::ChartThemeBlueCerulean);
    themeComboBox->addItem("Dark", QChart::ChartThemeDark);
    themeComboBox->addItem("Light", QChart::ChartThemeLight);
    themeComboBox->addItem("Brown Sand", QChart::ChartThemeBrownSand);
    themeComboBox->addItem("Blue NCS", QChart::ChartThemeBlueNcs);
    themeComboBox->addItem("High Contrast", QChart::ChartThemeHighContrast);
    themeComboBox->addItem("Blue Icy", QChart::ChartThemeBlueIcy);
    themeComboBox->addItem("Qt", QChart::ChartThemeQt);
    return themeComboBox;
}

QComboBox *GinaGraph::createAnimationBox() const{
    // settings layout
    QComboBox *animationComboBox = new QComboBox();
    animationComboBox->addItem("All Animations", QChart::AllAnimations);
    animationComboBox->addItem("GridAxis Animations", QChart::GridAxisAnimations);
    animationComboBox->addItem("Series Animations", QChart::SeriesAnimations);
    animationComboBox->addItem("No Animations", QChart::NoAnimation);
    return animationComboBox;
}

//Creates legend options.
QComboBox *GinaGraph::createLegendBox() const{
    QComboBox *legendComboBox = new QComboBox();
    legendComboBox->addItem("Legend Bottom", Qt::AlignBottom);
    legendComboBox->addItem("Legend Top", Qt::AlignTop);
    legendComboBox->addItem("Legend Left", Qt::AlignLeft);
    legendComboBox->addItem("Legend Right", Qt::AlignRight);
    legendComboBox->addItem("No Legend ", 0);
    return legendComboBox;
}

//Creates a line chart based on input data.
QChart *GinaGraph::createLineChart(std::vector< std::vector<double>> Data, std::vector<double> tData, QString title, QString type) const{
    QChart *chart = new QChart();
    int numOfLines = Data.size();

    QValueAxis *axisX = new QValueAxis;
    QValueAxis *axisY = new QValueAxis;
    axisX->setLabelFormat("%g");
    axisY->setLabelFormat("%g");
    axisX->setTitleText("Time Passed"); //sets the x label.

    //set's the number of ticks to plot the graphs with.
    axisX->setTickCount(m_xTicks);
    axisY->setTickCount(m_yTicks);

    //set's the y axis labels.
    if(type == "CLH"){
        axisY->setTitleText("Percentage");
    } else if (type == "D"){
        axisY->setTitleText("Particle Number/second");
    } else {
        axisY->setTitleText("Particle Number");
    }

    //performs a quick check to not graph the last part of the vector if it is all zeros.
    int count = 0;
    int numOfEntriesLast = Data[numOfLines-1].size();

    axisX->setRange(0, tData[-1]);

    std::int64_t maxY = 0;
    int index = 0;


    //sets the y scale from 0 to the maximum data value.
    if(type == "CLH"){
        maxY=100;
    } else {
        for(int n=0; n<numOfLines; n++){
            index = Data[n].size();
            if(Data[n][index-1] > maxY){
                maxY = Data[n][index-1];
            }
        }
    }
    axisY->setRange(0,maxY);

    //Get's the number of entries and checks if one is mostly zero to un-include it (fixes a bug).
    for(int x=0;x<numOfEntriesLast; x++){
        if(Data[numOfLines-1][x]==0){
            count++;
        }
    }
    if(count > numOfEntriesLast/2){
        numOfLines--;
    }


    //Plots each vector entry of the vector input as a graph and gives it appropriate labeling.
    for(int i=0; i<numOfLines ; i++){
        QLineSeries *series = new QLineSeries();

        int numOfEntries = Data[i].size();
        for(int n=0; n<numOfEntries ; n++){
            series->append(tData[n],Data[i][n]);
        }
        if (type == "N" || type == "D"){
            series->setName("Ion " + QString::number(i));
        } else if (type == "CLH"){
            if (i == 0){
                series->setName("Contamination");
                series->setColor("Red");
            } else if (i == 1) {
                series->setName("Loss");
            } else if (i == 2) {
                series->setName("Health");
            }
            //axisX->setRange(0, tData[-1]);
        }
        chart->addSeries(series);
        chart->setAxisX(axisX, series);
        chart->setAxisY(axisY, series);

    }
    //chart->createDefaultAxes(); //Set's a default axis with no labels
    chart->setTitle(title);

    return chart;
}

void GinaGraph::updateUI(){
    QChart::ChartTheme theme = (QChart::ChartTheme) m_themeComboBox->itemData(m_themeComboBox->currentIndex()).toInt();

    if (m_charts.at(0)->chart()->theme() != theme) {
        foreach (QChartView *chartView, m_charts)
            chartView->chart()->setTheme(theme);

        QPalette pal = window()->palette();
        if (theme == QChart::ChartThemeLight) {
            pal.setColor(QPalette::Window, QRgb(0xf0f0f0));
            pal.setColor(QPalette::WindowText, QRgb(0x404044));
        } else if (theme == QChart::ChartThemeDark) {
            pal.setColor(QPalette::Window, QRgb(0x121218));
            pal.setColor(QPalette::WindowText, QRgb(0xd6d6d6));
        } else if (theme == QChart::ChartThemeBlueCerulean) {
            pal.setColor(QPalette::Window, QRgb(0x40434a));
            pal.setColor(QPalette::WindowText, QRgb(0xd6d6d6));
        } else if (theme == QChart::ChartThemeBrownSand) {
            pal.setColor(QPalette::Window, QRgb(0x9e8965));
            pal.setColor(QPalette::WindowText, QRgb(0x404044));
        } else if (theme == QChart::ChartThemeBlueNcs) {
            pal.setColor(QPalette::Window, QRgb(0x018bba));
            pal.setColor(QPalette::WindowText, QRgb(0x404044));
        } else if (theme == QChart::ChartThemeHighContrast) {
            pal.setColor(QPalette::Window, QRgb(0xffab03));
            pal.setColor(QPalette::WindowText, QRgb(0x181818));
        } else if (theme == QChart::ChartThemeBlueIcy) {
            pal.setColor(QPalette::Window, QRgb(0xcee7f0));
            pal.setColor(QPalette::WindowText, QRgb(0x404044));
        } else {
            pal.setColor(QPalette::Window, QRgb(0xf0f0f0));
            pal.setColor(QPalette::WindowText, QRgb(0x404044));
        }
        window()->setPalette(pal);
    }

    bool checked = m_antialiasCheckBox->isChecked();
    foreach (QChartView *chart, m_charts)
        chart->setRenderHint(QPainter::Antialiasing, checked);

    QChart::AnimationOptions options(m_animatedComboBox->itemData(m_animatedComboBox->currentIndex()).toInt());
    if (m_charts.at(0)->chart()->animationOptions() != options) {
        foreach (QChartView *chartView, m_charts)
            chartView->chart()->setAnimationOptions(options);
    }

    Qt::Alignment alignment(m_legendComboBox->itemData(m_legendComboBox->currentIndex()).toInt());

    if (!alignment) {
        foreach (QChartView *chartView, m_charts)
            chartView->chart()->legend()->hide();
    } else {
        foreach (QChartView *chartView, m_charts) {
            chartView->chart()->legend()->setAlignment(alignment);
            chartView->chart()->legend()->show();
        }
    }
}

