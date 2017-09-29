//==========================================================================
// GINA (Generations of Implanted Nuclear Atrophy)
// Michigan State University - National Superconducting Cylotron Laboratory
// File: ginagraph.cpp
// Created By: Antonius Torode
// File Created: June 23, 2017
// Purpose: This file is the header file corresponding to ginagraph.cpp
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

#ifndef GINAGRAPH_H
#define GINAGRAPH_H

#include <QtWidgets/QWidget>
#include <QtCharts/QChartGlobal>
#include <vector>
#include <QString>
#include <QAction>
#include <QMenuBar>
#include <QPushButton>

QT_BEGIN_NAMESPACE
class QComboBox;
class QCheckBox;
QT_END_NAMESPACE

QT_CHARTS_BEGIN_NAMESPACE
class QChartView;
class QChart;
QT_CHARTS_END_NAMESPACE

typedef QPair<QPointF, QString> Data;
typedef QList<Data> DataList;
typedef QList<DataList> DataTable;

QT_CHARTS_USE_NAMESPACE

class GinaGraph: public QWidget
{
    Q_OBJECT
public:
    GinaGraph(std::vector<std::vector<double> > DatN, std::vector<std::vector<double> > DatD,
              std::vector< std::vector<double>> DatCLH, std::vector<double> tDat,
              std::int8_t xTicks, std::int8_t yTicks, QString process, QWidget *parent = 0);
    ~GinaGraph();

private Q_SLOTS:
    void updateUI();

private slots:
    void saveCharts();

private:
    DataTable generateRandomData(int listCount, int valueMax, int valueCount) const;
    QComboBox *createThemeBox() const;
    QComboBox *createAnimationBox() const;
    QComboBox *createLegendBox() const;
    void connectSignals();
    QChart *createLineChartExample() const;
    QChart *createSplineChartExample() const;
    QChart *createScatterChartExample() const;

    QChart *createLineChart(std::vector< std::vector<double>> Data, std::vector<double> tData, QString title, QString type) const;

    QAction *exitAction;
    QAction *saveAction;
    void createActions();
    QMenuBar* createMenuBar();

    bool saveChart();
    QChartView *chartViewN;
    QChartView *chartViewD;
    QChartView *chartViewCLH;

    std::vector< std::vector<double>> m_DataN;
    std::vector< std::vector<double>> m_DataD;
    std::vector< std::vector<double>> m_DataCLH;

    std::vector<double> m_tData;

    std::int8_t m_xTicks;
    std::int8_t m_yTicks;
    QString m_process;


    QList<QChartView *> m_charts;

    QPushButton *m_saveButton;
    QComboBox *m_themeComboBox;
    QCheckBox *m_antialiasCheckBox;
    QComboBox *m_animatedComboBox;
    QComboBox *m_legendComboBox;
    QString chartPath;
};

#endif /* GINAGRAPH_H */
