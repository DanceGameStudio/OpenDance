@ECHO off

echo Unpacking OpenCV...
7zip\7za.exe x -y -o..\3rdparty\opencv-4.7.0\build\x64\vc16\bin\ ..\3rdparty\opencv-4.7.0\build\x64\vc16\bin\opencv_world470d.7z

echo Unpacking OpenPose...
7zip\7za.exe x -y -o..\3rdparty\openpose\bin\ ..\3rdparty\openpose\bin\cublas64_11.7z
7zip\7za.exe x -y -o..\3rdparty\openpose\bin\ ..\3rdparty\openpose\bin\cublasLt64_11.7z
7zip\7za.exe x -y -o..\3rdparty\openpose\bin\ ..\3rdparty\openpose\bin\opencv_world420d.7z

echo Downloading OpenPose Models...
pushd ..\3rdparty\openpose\models\
getBaseModels.bat
getCOCO_and_MPII_optional.bat