#ifndef YOLO_H
#define YOLO_H

#ifdef OPENCV
#include "opencv2/highgui/highgui_c.h"
#include "opencv2/imgproc/imgproc_c.h"
#include "opencv2/core/version.hpp"
#if CV_MAJOR_VERSION == 3
#include "opencv2/videoio/videoio_c.h"
#endif
#endif

extern "C" {

    typedef struct{
        float left, top, right, bottom, cls, score;
    } boxWithScore;

    struct network;

    boxWithScore *py_test_yolo(network *net, IplImage *iplImage, float thresh, int *numDet);
    void freeNet(network *net);
    network *loadNet(const char *cfgfile, const char *weightfile, int gpuId);

}

#endif
