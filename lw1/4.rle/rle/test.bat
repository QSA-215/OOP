@echo off
SET MyProgram="%~1"

echo test1 1 pack
%MyProgram% pack input1.txt output1.txt || goto err
fc output1.txt trueOutputs\trueOutput1.txt > nul || goto err
echo complete

echo test2 1 unpack
%MyProgram% unpack output1.txt output2.txt || goto err
fc output2.txt input1.txt > nul || goto err
echo complete

echo test3 2 pack
%MyProgram% pack input2.txt output3.txt || goto err
fc output3.txt trueOutputs\trueOutput3.txt > nul || goto err
echo complete

echo test4 2 unpack
%MyProgram% unpack output3.txt output4.txt || goto err
fc output4.txt input2.txt > nul || goto err
echo complete

echo test5 wrong mode
%MyProgram% packing input1 output5 && goto err
echo complete

echo test6 - only 2 arguments
%MyProgram% input.txt output6.txt && goto err
echo complete

echo test7 - wrong input
%MyProgram% pack wrongInput.txt output7.txt && goto err
echo complete

echo test8 - wrong output
%MyProgram% pack input.txt onlyReadOutput.txt && goto err
echo complete

echo test9 - only input
%MyProgram% pack input.txt && goto err
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