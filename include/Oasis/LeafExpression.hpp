//
// Created by Matthew McCall on 7/2/23.
//

#ifndef OASIS_LEAFEXPRESSION_HPP
#define OASIS_LEAFEXPRESSION_HPP

#include "Expression.hpp"

namespace Oasis {

/**
 * A leaf expression.
 *
 * A leaf expression is an expression that has no children.
 *
 * @tparam DerivedT The type of the derived class.
 */
template <typename DerivedT>
class LeafExpression : public Expression {
public:
    [[nodiscard]] auto Copy() const -> std::unique_ptr<Expression> final
    {
        return std::make_unique<DerivedT>(*static_cast<const DerivedT*>(this));
    }

    auto Copy(tf::Subflow&) const -> std::unique_ptr<Expression> final
    {
        return std::make_unique<DerivedT>(*static_cast<const DerivedT*>(this));
    }

    [[nodiscard]] auto StructurallyEquivalent(const Expression& other) const -> bool final
    {
        return this->GetType() == other.GetType();
    }

    auto StructurallyEquivalent(const Expression& other, tf::Subflow& subflow) const -> bool final
    {
        return this->GetType() == other.GetType();
    }
};

} // Oasis

#endif // OASIS_LEAFEXPRESSION_HPP
