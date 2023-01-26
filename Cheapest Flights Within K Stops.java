class Solution {
	public int findCheapestPrice(int n, int[][] flights, int src, int dst, int K) {

		/**
		src --> map(dest, cost);
		*/

		Map<Integer, Map<Integer, Integer>> map = new HashMap<>();
		for (int i = 0; i < flights.length; i++) {
			if (!map.containsKey(flights[i][0])) {
				map.put(flights[i][0], new HashMap<>());
			}
			map.get(flights[i][0]).put(flights[i][1], flights[i][2]);
		}

		Queue<int[]> q = new PriorityQueue<>((a, b) -> 
											 (Integer.compare(a[0], b[0])));
		int[] init = new int[]{0, src, K + 1};
		q.offer(init);

		while (!q.isEmpty()) {
			int[] cur = q.poll();
			int price = cur[0];
			int city = cur[1];
			int stops = cur[2];
			if (city == dst) return price;
			if (stops > 0) {
				Map<Integer, Integer> map2 = 
					map.getOrDefault(city, new HashMap());
				for (int a : map2.keySet()) {
					q.add(new int[] {price + map2.get(a), a, stops - 1});
				}
			}
		}
		return -1;
	}
}
