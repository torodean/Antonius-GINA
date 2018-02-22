cd ../

rm -rf release/src/gina*
rm -rf release/src/GINA*
rm -rf release/src/main*
rm -rf release/src/Makefile
rm -rf release/bin
rm -rf release/README.txt
rm -rf release/Documentation

cp utilities/linuxdeployqt-continuous-x86_64.AppImage release/linuxdeployqt-continuous-x86_64.AppImage
cp -r bin/build-GINA-Desktop_Qt_5_9_0_GCC_64bit-Debug release/build-GINA-Desktop_Qt_5_9_0_GCC_64bit-Debug
cp bin/gina* release/src/
cp bin/GINA* release/src/
cp README.txt release/README.txt
cp bin/Makefile release/src/Makefile
mkdir release/Documentation
cp Documentation/Manual/GINA_Manual.pdf release/Documentation/GINA_Manual.pdf
cp Documentation/Original_Calculations/GINA_Calculations.pdf release/Documentation/GINA_Calculations.pdf

cd release/build-GINA-Desktop_Qt_5_9_0_GCC_64bit-Debug/
find \( -name "moc_*" -or -name "*.o" -or -name "qrc_*" -or -name "Makefile*" -or -name "*.a" \) -exec rm {} \;
rm -r Analysis Images

cd ../
chown $USER:$USER linuxdeployqt-continuous-x86_64.AppImage
chmod a+x linuxdeployqt-continuous-x86_64.AppImage
./linuxdeployqt-continuous-x86_64.AppImage build-GINA-Desktop_Qt_5_9_0_GCC_64bit-Debug/GINA
mv build-GINA-Desktop_Qt_5_9_0_GCC_64bit-Debug bin
rm -f linuxdeployqt-continuous-x86_64.AppImage


