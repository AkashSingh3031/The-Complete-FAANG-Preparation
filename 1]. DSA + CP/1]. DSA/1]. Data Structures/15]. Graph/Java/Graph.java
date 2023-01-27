import java.util.*;

public class Graph<T> {

    private Map<Object, ArrayList<Object>> map;
    private boolean bidirectional;

    public Graph() {
        map = new HashMap<>();
        this.bidirectional = true;
    }

    public Graph(boolean bidirectional) {
        map = new HashMap<>();
        this.bidirectional = bidirectional;
    }

    public void addEdge(T start, T end) {
        if (end == null && start != null) {
            map.put(start, new ArrayList<>());
            return;
        }
        if (start == null && end != null) {
            map.put(end, new ArrayList<>());
            return;
        }
        if (end == null && start == null) {
            return;
        }
        if (!map.containsKey(start)) {
            map.put(start, new ArrayList<>());
        }
        if (!map.containsKey(end)) {
            map.put(end, new ArrayList<>());
        }
        if (bidirectional) {
            map.get(start).add(end);
            map.get(end).add(start);
        } else {
            map.get(start).add(end);
        }
    }


    public List<List<T>> bfs() {
        HashSet<T> vis;
        vis = new HashSet<>();
        List<List<T>> ans = new ArrayList<>();
        map.forEach((k, v) -> {
            if (!vis.contains(k)) {
                ans.add(bfs((T) k, vis));
            }
        });
        return ans;
    }

    public List<T> bfs(T source) {
        if (!map.containsKey(source)) {
            return new ArrayList<>();
        }
        HashSet<T> vis = new HashSet<>();
        return this.bfs(source, vis);
    }

    private List<T> bfs(T source, HashSet<T> vis) {
        ArrayList<T> ans = new ArrayList<>();
        Queue<T> queue = new LinkedList<>();
        queue.add(source);
        vis.add(source);
        while (!queue.isEmpty()) {
            T node = queue.poll();
            ans.add(node);
            map.get(node).forEach(item -> {
                if (!vis.contains((T) item)) {
                    vis.add((T) item);
                    queue.add((T) item);
                }

            });
        }
        return ans;
    }

    public List<List<T>> dfs() {
        List<List<T>> ans = new ArrayList<>();
        HashSet<T> visited = new HashSet<>();
        map.forEach((k, v) -> {
            if (!visited.contains(k)) {
                ans.add(this.dfs((T) k, visited));
            }
        });
        return ans;
    }

    // return only a component of graph containing that source in it
    public List<T> dfs(T source) {
        if (!map.containsKey(source)) {
            return new ArrayList<>();
        }
        HashSet<T> vis = new HashSet<>();
        return this.dfs(source, new HashSet<>());
    }

    private List<T> dfs(T s, HashSet<T> visited) {
        ArrayList<T> ret = new ArrayList<>();
        ret.add(s);
        visited.add(s);
        map.get(s).forEach((Object item) -> {
            if (!visited.contains(item)) {
                ret.addAll(dfs((T) item, visited));
            }
        });
        return ret;
    }

    @Override // returns adjacency map 
    public String toString() {
        return map.toString();
    }

    // Main function
    public static void main(String[] args) {

        // A Undirected graph of String(Countries)
        Graph<String> graph = new Graph<>();
        graph.addEdge("India", "Japan");
        graph.addEdge("India", "USA");
        graph.addEdge("Russia", "USA");
        graph.addEdge("Korea", "Malaysia");
        System.out.println(graph.dfs());
        System.out.println(graph.bfs());

        // dfs for a single component
        System.out.println(graph.dfs("India"));
        // bfs for a single component
        System.out.println(graph.bfs("Japan"));

        System.out.println(); // for line gap in output

        // A directed graph of integers
        Graph<Integer> directed=new Graph<>(false);
        directed.addEdge(0,1);
        directed.addEdge(0,2);
        directed.addEdge(2,3);
        directed.addEdge(3,1);
        directed.addEdge(2,4);
        directed.addEdge(3,5);
        System.out.println(directed.dfs());
        System.out.println(directed.bfs());

    }

}
