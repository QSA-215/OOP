@echo off

echo test1
invert.exe matrix1.txt > output1.txt || goto err
fc output1.txt trueOutputs\trueOutput1.txt > nul || goto err
echo complete

echo test2
invert.exe matrix2.txt > output2.txt || goto err
fc output2.txt trueOutputs\trueOutput2.txt > nul || goto err
echo complete

echo test3
invert.exe matrix3.txt > output3.txt || goto err
fc output3.txt trueOutputs\trueOutput3.txt > nul || goto err
echo complete

echo test4 no inverse matrix
invert.exe matrix4.txt && goto err
echo complete

echo test5 invalid input
invert.exe wrongMatrix.txt && goto err
echo complete

REM Всё прошло без ошибок
echo All tests completed successfully
pause
exit /B 0

REM Случилась ошибка
:err
echo Test failed
pause
exit /B 1