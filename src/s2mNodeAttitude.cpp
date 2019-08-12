#define BIORBD_API_EXPORTS
#include "s2mNodeAttitude.h"

#include <Eigen/Dense>

s2mNodeAttitude::s2mNodeAttitude(
        const biorbd::utils::Attitude &v,
        const s2mString &name,
        const s2mString &parentName) : // Nom du parent
    biorbd::utils::Attitude(v),
    m_parentName(parentName),
    m_RTName(name)
{

}

s2mNodeAttitude::~s2mNodeAttitude()
{
    //dtor
}

const s2mString &s2mNodeAttitude::parent() const
{
    return m_parentName;
}

void s2mNodeAttitude::setParent(const s2mString &parentName)
{
    m_parentName = parentName;
}

void s2mNodeAttitude::setAttitude(const Attitude &n)
{
    this->block(0,0,4,4) = n.block(0,0,4,4);
}


const biorbd::utils::Attitude &s2mNodeAttitude::attitude() const
{
    return *this;
}


void s2mNodeAttitude::setName(const s2mString &name)
{
    m_RTName = name;
}

const s2mString &s2mNodeAttitude::name() const
{
    return m_RTName;
}

