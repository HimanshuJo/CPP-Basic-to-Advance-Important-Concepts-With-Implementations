'''

Problem:

	There are n gas stations along a circular route, where the amount of gas at the ith station
		is gas[i]

		We have a car with an unlimited gas tank and it costs cost[i] of 'gas' to travel from the
			ith station to station to its next (i + 1)th station

		We begin the journey with an empty tank at one of the gas stations

	Given two integers arrays
		gas and cost, return the starting gas station's index if we can travel around the circuit
			once in the clockwise direction, otherwise return -1

		If there exists a solution, it is guaranteed that it should be unique

	-------

	Example 1:
				 [0 1 2 3 4]
	Input: gas = [1,2,3,4,5], cost = [3,4,5,1,2]
	Output: 3
	Explanation: we can't start at station 0 as, it gives only 1 unit of gas and cost to its next station is 3
	Start at station 3 (index 3) and fill up with 4 unit of gas. Your tank = 0 + 4 = 4
	Travel to station 4. Your tank = 4 - 1 + 5 = 8
	Travel to station 0. Your tank = 8 - 2 + 1 = 7
	Travel to station 1. Your tank = 7 - 3 + 2 = 6
	Travel to station 2. Your tank = 6 - 4 + 3 = 5
	Travel to station 3. The cost is 5. Your gas is just enough to travel back to station 3.
	Therefore, return 3 as the starting index.

	Example 2:

	Input: gas = [2,3,4], cost = [3,4,3]
	Output: -1
	Explanation:
	You can't start at station 0 or 1, as there is not enough gas to travel to the next station.
	Let's start at station 2 and fill up with 4 unit of gas. Your tank = 0 + 4 = 4
	Travel to station 0. Your tank = 4 - 3 + 2 = 3
	Travel to station 1. Your tank = 3 - 3 + 3 = 3
	You cannot travel back to station 2, as it requires 4 unit of gas but you only have 3.
	Therefore, you can't travel around the circuit once no matter where you start.

-------

Tricky Intuition:

	First thing we need to know is that
		if the total sum of the gas >= total cost
			then we know that there has to be a station that will allow us to finish the whole trip

	Next thing is to find the appropriate station

		we will initially loop through the first station
			we keep like a currentGas or Tank

			on each station our tank will get filled up
				we can do this by keep adding the differences of the gas and the cost

					tank += gas[i] - cost[i]  (same as the above equation  --> tank - cost[i] + gas[i])

			so basically we are accumulating all the gases we have seen so far and all the cost
				we have seen so far

				and we will check if the tank is < 0

			If the tank is < 0 it means that

				we can't go from the current station to the next station
					we don't have enough tank

			** In this case, we need to move our start point to our current i + 1
					and we also need to clear this tank to 0

	In the end we can finally return the start

	-------

	Suppose we have 5 stations 1, 2, 3, 4, 5

		and suppose at station 4 our tank goes less than 0

		In this case, we know that if there is a station that will allow us to travel the whole circuit
			that station has to be at the right of this station

			Proof:

				Because, from the previous stations till this stations we have already accumulated all the gas and all the cost

					at the 4th station, the condition the has arised is
							totalGas < totalCost

					the previous stations were not the valid stations and haven't provided the sufficient gas

					Maybe in previous stations we were able to move from one station to the next
						but now we are stuck at 4, as the prev gas was not valid enough

						there is no way we can make the previous stations valid

'''

class Solution:
	
	def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
		if sum(gas) < sum(cost):
			return -1
		tank = 0
		start = 0
		for i in range(len(gas)):
			tank += gas[i] - cost[i]

			if tank < 0:
				# we are being optimistic here, every-time there is not enough gas here, we can think 
				# there will be enough gas later
				start = i + 1
				tank = 0
		return start
