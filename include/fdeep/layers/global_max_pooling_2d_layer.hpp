// Copyright 2016, Tobias Hermann.
// https://github.com/Dobiasd/frugally-deep
// Distributed under the MIT License.
// (See accompanying LICENSE file or at
//  https://opensource.org/licenses/MIT)

#pragma once

#include "fdeep/layers/global_pooling_layer.hpp"

namespace fdeep { namespace internal
{

class global_max_pooling_2d_layer : public global_pooling_layer
{
public:
    explicit global_max_pooling_2d_layer(const std::string& name) :
    global_pooling_layer(name)
    {
    }
protected:
    tensor3 pool(const tensor3& in) const override
    {
        tensor3 out(shape3(1, 1, in.shape().depth_), 0);
        for (std::size_t z = 0; z < out.shape().depth_; ++z)
        {
            float_type val = 0;
            for (std::size_t y = 0; y < out.shape().height_; ++y)
            {
                for (std::size_t x = 0; x < out.shape().width_; ++x)
                {
                    val = std::max(val, in.get(z, y, x));
                }
            }
            out.set(0, 0, z, val);
        }
        return out;
    }
};

} } // namespace fdeep, namespace internal