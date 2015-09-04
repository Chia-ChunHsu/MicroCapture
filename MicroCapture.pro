#-------------------------------------------------
#
# Project created by QtCreator 2015-08-22T11:47:52
#
#-------------------------------------------------

QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = FourCapture
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    thread_stitch.cpp \
    stitch.cpp \
    autocameradialog.cpp

HEADERS  += mainwindow.h \
    thread_stitch.h \
    stitch.h \
    autocameradialog.h

FORMS    += mainwindow.ui \
    autocameradialog.ui
INCLUDEPATH += $$quote(D:\opencv 2.4.9.1\include)\
               $$quote(D:\opencv 2.4.9.1\include\opencv2)

OPENCVLIB += $$quote(D:\opencv 2.4.9.1\x64\vc12\lib)

CONFIG(debug, debug|release){
LIBS+= $$OPENCVLIB/opencv_core249d.lib\
       $$OPENCVLIB/opencv_highgui249d.lib\
       $$OPENCVLIB/opencv_features2d249d.lib\
       $$OPENCVLIB/opencv_flann249d.lib\
       $$OPENCVLIB/opencv_nonfree249d.lib\
       $$OPENCVLIB/opencv_imgproc249d.lib\
       $$OPENCVLIB/opencv_ocl249d.lib\
       $$OPENCVLIB/opencv_stitching249d.lib
}

CONFIG(release, debug|release){
LIBS+= $$OPENCVLIB/opencv_core249.lib\
       $$OPENCVLIB/opencv_highgui249.lib\
       $$OPENCVLIB/opencv_features2d249.lib\
       $$OPENCVLIB/opencv_flann249.lib\
       $$OPENCVLIB/opencv_nonfree249.lib\
       $$OPENCVLIB/opencv_imgproc249.lib\
       $$OPENCVLIB/opencv_ocl249.lib\
       $$OPENCVLIB/opencv_stitching249.lib
}

DEFINES += HAVE_OPENCV
