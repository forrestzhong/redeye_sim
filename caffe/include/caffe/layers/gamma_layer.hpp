#ifndef CAFFE_GAMMA_LAYER_HPP_
#define CAFFE_GAMMA_LAYER_HPP_

#include <vector>
#include "caffe/blob.hpp"
#include "caffe/layer.hpp"
#include "caffe/proto/caffe.pb.h"

namespace caffe {
/** 
 * @brief A layer that uncorrect the gamma correction on input images.
 *
 */
  template <typename Dtype>
  class GammaLayer : public Layer<Dtype> {
   public:
    explicit GammaLayer(const LayerParameter& param) : Layer<Dtype>(param) {}
    virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
        const vector<Blob<Dtype>*>& top);
    virtual void Reshape(const vector<Blob<Dtype>*>& bottom, 
      const vector<Blob<Dtype>*>& top) {top[0]->Reshape(bottom[0]->shape());}
    virtual inline const char* type() const { return "Gamma"; }
    virtual inline int MinBottomBlobs() const { return 1; }
    virtual inline int ExactNumTopBlobs() const { return 1; }
   protected:
    virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
        const vector<Blob<Dtype>*>& top);
    virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
        const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom) {}
    virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
        const vector<Blob<Dtype>*>& top);
    virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
        const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
    // parameters for gamma
    Dtype _gamma;
  };
}

#endif // CAFFE_GAMMA_LAYER_HPP_