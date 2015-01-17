// Copyright Hugh Perkins 2014 hughperkins at gmail
//
// This Source Code Form is subject to the terms of the Mozilla Public License, 
// v. 2.0. If a copy of the MPL was not distributed with this file, You can 
// obtain one at http://mozilla.org/MPL/2.0/.

#pragma once

#include <stdexcept>
#include <string>
#include <iostream>

#include "MyRandom.h"
#include "ActivationFunction.h"
#include "LayerMaker.h"
#include "stringhelper.h"
#include "OpenCLHelper.h"

#define VIRTUAL virtual

class Layer {
public:
//    int batchStart;
//    int batchEnd;

    Layer *previousLayer;
    Layer *nextLayer;
//    const int numPlanes;
//    const int boardSize;
//    const bool biased;
//    ActivationFunction const *const activationFunction;
//    const int upstreamBoardSize;
//    const int upstreamNumPlanes;
    const int layerIndex;
//    bool weOwnResults;

//    const int boardSizeSquared;
//    const int upstreamBoardSizeSquared;

//    int batchSize;

//    virtual bool needErrorsBackprop() = 0;

    // results structured like [imageid][outputplane][outputrow][outputcol]
//    inline int getResultIndex( int n, int plane, int row, int col ) const {
//        return ( ( ( n * numPlanes ) + plane ) * boardSize + row ) * boardSize + col;
//    }
//    inline float getResult( int n, int plane, int row, int col ) const {
//        return results[getResultIndex( n, plane,row,col)];
//    }
//    inline int getResultsSizePerExample() const {
//        return numPlanes * boardSize * boardSize;
//    }
    virtual float * getResults() = 0;

    // [[[cog
    // import cog_addheaders
    // cog_addheaders.add()
    // ]]]
    // classname: Layer
    // cppfile: Layer.cpp

    Layer( Layer *previousLayer, LayerMaker const*maker );
    VIRTUAL ~Layer();
    VIRTUAL void setBatchSize( int batchSize );
    VIRTUAL bool providesErrorsForUpstreamWrapper() const;
    VIRTUAL float *getErrorsForUpstream();
    VIRTUAL CLWrapper *getErrorsForUpstreamWrapper();
    VIRTUAL bool getBiased() const;
    VIRTUAL bool hasResultsWrapper() const;
    VIRTUAL CLWrapper *getResultsWrapper();
    VIRTUAL ActivationFunction const*getActivationFunction();
    VIRTUAL int getResultsSize() const;
    VIRTUAL int getOutputCubeSize() const;
    VIRTUAL int getOutputPlanes() const;
    VIRTUAL int getOutputBoardSize() const;
    VIRTUAL void propagate();
    VIRTUAL void print() const;
    VIRTUAL void initWeights( float*weights );
    VIRTUAL void initBiasWeights( float*biasWeights );
    VIRTUAL void printWeightsAsCode() const;
    VIRTUAL void printBiasWeightsAsCode() const;
    VIRTUAL void printWeights() const;
    VIRTUAL void printOutput() const;
    VIRTUAL void backProp( float learningRate );
    VIRTUAL int getWeightsSize() const;
    VIRTUAL int getBiasWeightsSize() const;
    VIRTUAL void setWeights(float *weights, float *biasWeights);
    VIRTUAL float const *getWeights() const;
    VIRTUAL float *getWeights();
    VIRTUAL float const*getBiasWeights() const;

    // [[[end]]]

};

