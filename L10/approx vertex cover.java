/*
* @Author: nevil11
* @Date:   2020-10-25 17:37:11
* @Last Modified by:   nevil11
* @Last Modified time: 2020-10-25 17:43:40
*/
package vcp;
import java.util.*;
import java.util.LinkedList;

class VCP {
	private int V;

	VCP(int v) {
		V = v;
	}

	void printVertexCover(int g[][]) {
		boolean visited[] = new boolean[V];
		for (int i = 0; i < V; i++)
			visited[i] = false;

		for (int i = 0; i < V; i++) {
			if (!visited[i]) {
				for (int j = 0; j < V; j++) {
					if (g[i][j] == 1 && !visited[j]) {
						visited[i] = true;
						visited[j] = true;
						break;
					}
				}

			}
		}


		for (int j = 0; j < V; j++)
			if (visited[j])
				System.out.print(j + " ");
	}
	public static void main(String args[]) {
		VCP g = new VCP(4);

		int[][] graph = {{0, 1, 1, 0},
			{1, 0, 1, 1},
			{1, 1, 0, 1},
			{0, 1, 1, 0}
		};

		System.out.println();
		g.printVertexCover(graph);
		System.out.println();
	}
}