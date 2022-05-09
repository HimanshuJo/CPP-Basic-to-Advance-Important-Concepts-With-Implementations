/*
	LeetCode wants to give one of its best employees the option to travel among N cities to collect algorithm problems.
	But all work and no play makes Jack a dull boy, you could take vacations in some particular cities and weeks.
	Your job is to schedule the traveling to maximize the number of vacation days you could take, but there are certain
		rules and restrictions you need to follow.

Rules and restrictions:

    You can only travel among N cities, represented by indexes from 0 to N-1.
    Initially, you are in the city indexed 0 on Monday.

    The cities are connected by flights. The flights are represented as a N*N matrix (not necessary symmetrical),
    called flights representing the airline status from the city i to the city j.

    	If there is no flight from the city i to the city j, flights[i][j] = 0;
    	Otherwise, flights[i][j] = 1. Also, flights[i][i] = 0 for all i.

    You totally have K weeks (each week has 7 days) to travel.
    	You can only take flights at most once per day and can only take flights on each week's
    	Monday morning. Since flight time is so short, we don't consider the impact of flight time.

    For each city, you can only have restricted vacation days in different weeks,
    	given an N*K matrix called days representing this relationship.

    	For the value of days[i][j], it represents the maximum days you could take vacation
    	in the city i in the week j.

You're given the flights matrix and days matrix, and you need to output the maximum vacation days
you could take during K weeks.

Example 1:

Input:flights = [[0,1,1],[1,0,1],[1,1,0]], days = [[1,3,1],[6,0,3],[3,3,3]]
Output: 12
Explanation:
Ans = 6 + 3 + 3 = 12.

One of the best strategies is:
	1st week : fly from city 0 to city 1 on Monday, and play 6 days and work 1 day.
	(Although you start at city 0, we could also fly to and start at other cities since it is Monday.)

	2nd week : fly from city 1 to city 2 on Monday, and play 3 days and work 4 days.

	3rd week : stay at city 2, and play 3 days and work 4 days.

-------
*/

import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

public class Solution {
	public int maxVacationDays(int[][] flights, int[][] days) {
		// with the help of a map creating a flights graph here
		// for a particular city, which cities we can visit
		// key will be a city (0, 1, 2 ..) and values will be list of cities we can go from that city
		HashMap<Integer, List<Integer>> reach = new HashMap<>();
		for (int i = 0; i < flights.length; ++i) {
			List<Integer> list = new LinkedList<>();
			for (int j = 0; j < flights[i].length; ++j) {
				if (flights[i][j] == 1) {
					list.add(j);
				}
			}
			reach.put(i, list);
		}
		int[] max = new int[flights.length];
		boolean[] stay = new boolean[flights.length];
		stay[0] = true;
		// only need to start with days[0], cover rest while doing BFS
		for (int week = 0; week < days[0].length; ++week) {
			int[] newMax = new int[flights.length];
			boolean[] newStay = new boolean[flights.length];
			Queue<Integer> q = new LinkedList<Integer>();
			for (int city = 0; city < max.length; ++city) {
				if (stay[city] == true) {
					q.add(city);
				}
			}
			while (!q.isEmpty()) {
				int city = q.poll();
				newMax[city] = Math.max(newMax[city], max[city] + days[city][week]);
				newStay[city] = true;
				for (int j : reach.get(city)) {
					if (max[city] + days[j][week] > newMax[j] || newStay[j] == false) {
						newMax[j] = max[city] + days[j][week];
						q.add(j);
					}
					newStay[j] = true;
				}
			}
			stay = newStay;
			max = newMax;
		}
		int res = 0;
		for (int i = 0; i < max.length; ++i) {
			res = Math.max(res, max[i]);
		}
		return res;
	}

	public static void main(String[] args) {
		Solution obj = new Solution();
		int[][] flights = { { 0, 1, 1 }, { 1, 0, 1 }, { 1, 1, 0 } };
		int[][] days = { { 1, 3, 1 }, { 6, 0, 3 }, { 3, 3, 3 } };
		System.out.println(obj.maxVacationDays(flights, days));
	}
}
