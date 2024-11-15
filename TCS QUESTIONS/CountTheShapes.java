import java.util.*;

public class CountTheShapes {
    // Method to find the number of closed figures
    public static int countClosedFigures(List<int[]> lines) {
        // Graph to store adjacency list
        Map<String, List<String>> graph = new HashMap<>();

        // Add edges to the graph
        for (int[] line : lines) {
            String point1 = line[0] + "," + line[1];
            String point2 = line[2] + "," + line[3];

            graph.putIfAbsent(point1, new ArrayList<>());
            graph.putIfAbsent(point2, new ArrayList<>());

            graph.get(point1).add(point2);
            graph.get(point2).add(point1);
        }

        // To track visited nodes
        Set<String> visited = new HashSet<>();
        int closedFigures = 0;

        // Perform DFS to count cycles
        for (String node : graph.keySet()) {
            if (!visited.contains(node)) {
                if (isCycle(node, graph, visited, null)) {
                    closedFigures++;
                }
            }
        }

        return closedFigures;
    }

    // Helper method to perform DFS and detect a cycle
    private static boolean isCycle(String node, Map<String, List<String>> graph, Set<String> visited, String parent) {
        visited.add(node);
        boolean hasCycle = false;

        for (String neighbor : graph.get(node)) {
            if (!visited.contains(neighbor)) {
                // Continue DFS
                if (isCycle(neighbor, graph, visited, node)) {
                    hasCycle = true;
                }
            } else if (!neighbor.equals(parent)) {
                // Cycle detected
                hasCycle = true;
            }
        }

        return hasCycle;
    }

    // Main method to handle input and output
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Number of lines
        int n = sc.nextInt();
        List<int[]> lines = new ArrayList<>();

        // Read line segments
        for (int i = 0; i < n; i++) {
            int x1 = sc.nextInt();
            int y1 = sc.nextInt();
            int x2 = sc.nextInt();
            int y2 = sc.nextInt();
            lines.add(new int[]{x1, y1, x2, y2});
        }

        // Count closed figures
        int result = countClosedFigures(lines);
        System.out.println(result);

        sc.close();
    }
}



15
0 0 1 0
3 1 3 3
3 3 1 3
5 3 4 3
5 4 6 4
1 0 0 1
0 1 0 0
1 1 3 1
6 4 6 3
1 3 1 1
4 1 5 1
6 3 6 2
5 1 5 3
3 0 4 0
4 3 4 1
