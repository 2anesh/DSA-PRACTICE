class Solution {
	public double[] calcEquation(List<List<String>> equations, double[] values, List<List<String>> queries) {
		Map<String, Map<String, Double>> graph = new HashMap<>();
		buildGraph(graph, equations, values);
		double[] res = new double[queries.size()];
		Arrays.fill(res, -1.0);
		int idx = 0;

		for (List<String> q : queries) {
			String a = q.get(0);
			String b = q.get(1);

			if (!graph.containsKey(a) || !graph.containsKey(b)) idx++;
			else{
				dfs(graph, a, b, res, idx, new HashSet<>(), 1.0);
				idx++;
			}

		}
		return res;
	}

	private void buildGraph(Map<String, Map<String, Double>> graph,List<List<String>> equations, double[] values) {
		int idx = 0;
		for (List<String> eq : equations) {
			String a = eq.get(0);
			String b = eq.get(1);
			graph.putIfAbsent(a, new HashMap<>());
			graph.putIfAbsent(b, new HashMap<>());
			graph.get(a).put(b, values[idx]);
			graph.get(b).put(a, 1 / values[idx]);
			idx++;
			graph.get(a).put(a, 1.0);
			graph.get(b).put(b, 1.0);
		}
	}

	private void dfs(Map<String, Map<String, Double>> graph, String a, String b, double[] res, int idx, Set<String> visited, double tmp) {
		visited.add(a);
		if (graph.get(a).containsKey(b)) {
			res[idx] = graph.get(a).get(b) * tmp;
			return;
		}
		for (String next : graph.get(a).keySet()) {
			if (visited.contains(next)) continue;
			dfs(graph, next, b, res, idx, visited, graph.get(a).get(next) * tmp);
		}
	}
}
