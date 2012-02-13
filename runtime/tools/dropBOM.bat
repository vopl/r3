
FOR /R . %%i IN (*.hpp *.cpp *.h) DO iconv -f UTF-8 -t UTF-32 %%i > %%i.32

FOR /R . %%i IN (*.hpp *.cpp *.h) DO iconv -f UTF-32 -t UTF-8 %%i.32 > %%i

FOR /R . %%i IN (*.hpp *.cpp *.h) DO rm %%i.32

