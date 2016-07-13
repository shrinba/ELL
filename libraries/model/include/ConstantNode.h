////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Project:  Embedded Machine Learning Library (EMLL)
//  File:     ConstantNode.h (model)
//  Authors:  Chuck Jacobs
//
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "Node.h"
#include "OutputPort.h"
#include "ModelTransformer.h"

#include <vector>
#include <memory>

/// <summary> model namespace </summary>
namespace model
{
    /// <summary> A node that contains a constant value. Has no inputs. </summary>
    template <typename ValueType>
    class ConstantNode : public Node
    {
    public:
        /// <summary> Constructor for a scalar constant </summary>
        ///
        /// <param name="value"> The scalar value </param>
        ConstantNode(ValueType value);

        /// Constructor for a vector constant
        ///
        /// <param name="value"> The vector value </param>
        ConstantNode(const std::vector<ValueType>& values);

        /// <summary> Gets the name of this type (for serialization). </summary>
        ///
        /// <returns> The name of this type. </returns>
        static std::string GetTypeName() { return "Constant"; }

        /// <summary> Gets the name of this type (for serialization). </summary>
        ///
        /// <returns> The name of this type. </returns>
        virtual std::string GetRuntimeTypeName() const override { return GetTypeName(); }

        /// <summary> Exposes the output port as a read-only property </summary>
        const OutputPort<ValueType>& output = _output;

        virtual void Copy(ModelTransformer& transformer) const override;
        virtual void Refine(ModelTransformer& transformer) const override;

    protected:
        virtual void Compute() const override;

    private:
        std::vector<ValueType> _values;
        OutputPort<ValueType> _output;
    };
}

#include "../tcc/ConstantNode.tcc"