@echo off
SET MyProgram = "%~1"

echo test1 - "9" replace by "x"
%MyProgram% input.txt output1.txt 9 x || goto err
fc output1.txt trueOutputs\trueOutput1.txt > nul || goto err
echo complete

echo test2 - "ma" replace by "mama"
%MyProgram% input.txt output2.txt ma mama || goto err
fc output2.txt trueOutputs\trueOutput2.txt > nul || goto err
echo complete

echo test3 - "1231234" replace by "xxx"
%MyProgram% input.txt output3.txt 1231234 xxx || goto err
fc output3.txt trueOutputs\trueOutput3.txt > nul || goto err
echo complete

echo test4 - "roma" replace by "natasha"
%MyProgram% input.txt output4.txt roma natasha || goto err
fc output4.txt input.txt > nul || goto err
echo complete

echo test5 - "9" replace by ""
%MyProgram% input.txt output5.txt 9 || goto err
fc output5.txt trueOutputs\trueOutput5.txt > nul || goto err
echo complete

echo test6 - only 2 arguments
%MyProgram% input.txt output6.txt || goto err
fc output6.txt input.txt > nul || goto err
echo complete

echo test7 - wrong input
%MyProgram% wrongInput.txt output7.txt && goto err
echo complete

echo test8 - wrong output
%MyProgram% input.txt onlyReadOutput.txt && goto err
echo complete

echo test9 - only input
%MyProgram% input.txt && goto err
echo complete

echo test10 - no input
%MyProgram% && goto err
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