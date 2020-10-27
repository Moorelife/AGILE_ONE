#pragma once

#include "NeuronBase.h"
#include "SynapseBase.h"
#include <queue>
#include <vector>
#include <atomic>
#define NeuronWrapper _

namespace NeuronEngine
{
	class NeuronArrayBase
	{
	public:
		NeuronArrayBase();
		~NeuronArrayBase();
		void Initialize(int theSize, NeuronBase::modelType t = NeuronBase::modelType::Std);
		NeuronBase* GetNeuron(int i);
		int GetArraySize();
		long long GetTotalSynapseCount();
		long GetNeuronsInUseCount();
		void Fire();
		long long GetGeneration();
		int GetFiredCount();
		int GetThreadCount();
		void SetThreadCount(int i);
		void GetBounds(int taskID, int& start, int& end);
		std::string GetRemoteFiringString();
		SynapseBase GetRemoteFiringSynapse();
        
#ifndef PARALLEL_PROCESSING        
        static std::queue<SynapseBase> remoteQueue;
        static std::queue<NeuronBase*> fire2Queue;
#endif        

	private:
		int arraySize = 0;
		int threadCount = 124;//TODO
		std::vector<NeuronBase> neuronArray;
		std::atomic<long> firedCount{0};
        long generation = 0;

        
		static std::vector<unsigned long long> fireList1;
		static std::vector<unsigned long long> fireList2;
		static int fireListCount;

	private:
		void ProcessNeurons1(int taskID); //these are noinlined so the profiler makes more sense
		void ProcessNeurons2(int taskID);
	public:
		static void AddNeuronToFireList1(int id);
		static bool clearFireListNeeded;
		static void ClearFireLists();
	};
}
