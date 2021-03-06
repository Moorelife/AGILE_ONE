﻿// #define _GLIBCXX_USE_CXX11_ABI 0

#include "options.h"
#include "SynapseBase.h"
#include "NeuronBase.h"

namespace NeuronEngine
{
	NeuronBase* SynapseBase::GetTarget()
	{
		return targetNeuron;
	}
	void SynapseBase::SetTarget(NeuronBase* target)
	{
		targetNeuron = target;
	}
	float SynapseBase::GetWeight()
	{
		return weight;
	}
	void SynapseBase::SetWeight(float value)
	{
		weight = value;
	}
	bool SynapseBase::IsHebbian()
	{
		return isHebbian;
	}
	void SynapseBase::SetIsHebbian(bool value)
	{
		isHebbian = value;
	}
}
