class Solution(object):
    def canCompleteCircuit(self, gas, cost):
        """
        :type gas: List[int]
        :type cost: List[int]
        :rtype: int
        """
        n = len(gas)

        currentGas = 0
        cst = 0
        netGas = [0] * n
        for i in range(n):
            currentGas += gas[i]
            cst += cost[i]
            netGas[i] = gas[i] - cost[i]

        if cst > currentGas:
            return -1
        
        ans = -1
        total = 0
        for i in range(n):
            if total + netGas[i] < 0:
                ans = -1
                total = 0
            else:
                total += netGas[i]
                if ans == -1:
                    ans = i
    
        return ans
