// Copyright (C) 2011  Dmitri Nikulin
// Copyright (C) 2011  Monash University
//
// Permission is hereby granted, free of charge, to any person
// obtaining a copy of this software and associated documentation
// files (the "Software"), to deal in the Software without
// restriction, including without limitation the rights to use,
// copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the
// Software is furnished to do so, subject to the following
// conditions:
//
// The above copyright notice and this permission notice shall be
// included in all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
// EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
// OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
// NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
// HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
// WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
// OTHER DEALINGS IN THE SOFTWARE.

#ifndef __CVD_CL_TO_UVQ_UV_STEP_HH__
#define __CVD_CL_TO_UVQ_UV_STEP_HH__

#include <cvd-cl/states/CameraState.hh>
#include <cvd-cl/states/ListState.hh>
#include <cvd-cl/states/UvqUvState.hh>
#include <cvd-cl/worker/WorkerStep.hh>

namespace CVD {
namespace CL  {

/// \brief WorkerStep to translate paired point lists to ((u,v,q),(u,v)) records.
///
/// \see HipsFindStep
/// \see HipsTreeFindStep
class ToUvqUvStep : public WorkerStep {
public:

    /// \brief Construct the step.
    ///
    /// \param i_camera   Input camera configuration.
    /// \param i_xy1      Input point list 1.
    /// \param i_xy2      Input point list 2.
    /// \param i_matches  Input match indices between list 1 and list 2.
    /// \param o_uvquv    Output ((u,v,q),(u,v)) records.
    explicit ToUvqUvStep(CameraState & i_camera, PointListState & i_xy1, PointListState & i_xy2, PointListState & i_matches, UvqUvState<1> & o_uvquv);

    /// \brief De-construct the step.
    virtual ~ToUvqUvStep();

    virtual void execute();

protected:

    /// \brief Input camera configuration.
    CameraState     & i_camera;

    /// \brief Input point list 1.
    PointListState  & i_xy1;

    /// \brief Input point list 2.
    PointListState  & i_xy2;

    /// \brief Input match indices between list 1 and list 2.
    PointListState  & i_matches;

    /// \brief Output ((u,v,q),(u,v)) records.
    UvqUvState<1>   & o_uvquv;

    /// \brief OpenCL program.
    cl::Program       program;

    /// \brief OpenCL kernel.
    cl::Kernel        kernel;
};

} // namespace CL
} // namespace CVD

#endif /* __CVD_CL_TO_UVQ_UV_STEP_HH__ */
