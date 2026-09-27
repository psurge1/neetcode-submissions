class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        n = len(temperatures)
        results = [0] * n
        future_temps = [(temperatures[-1], n - 1)]
        for day in range(n - 2, -1, -1):
            while len(future_temps) > 0 and temperatures[day] >= future_temps[-1][0]:
                future_temps.pop()
            if len(future_temps) > 0:
                results[day] = future_temps[-1][1] - day
            future_temps.append((temperatures[day], day))
        return results