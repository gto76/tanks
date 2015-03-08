:: set path
set PATH "%PATH%;C:\Program Files (x86)\DOSBox-0.74"
:: configure dosbox
echo mount t %cd%\bin >> "C:%homepath%\AppData\Local\DOSBox\dosbox-0.74.conf"
:: start dosbox
dosbox -fullscreen -c "t:" -c "tanks!"