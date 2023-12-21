package io.philo.codingtest.ch_2__d_bfs._1__이론

/**
 * DFS
 *
 *    1
 *  2    3
 * 4 5
 */
private val n = 6

private val adj = Array<MutableList<Int>>(6) { mutableListOf() }
private val vis = IntArray(6) { 0 }

fun main() {

    adj[1].addAll(listOf(2, 3))
    adj[2].addAll(listOf(4, 5))

    dfs(1)
}

private fun dfs(n: Int) {
    vis[n] = 1
    println(n)
    val list = adj[n]

    for (n in list) {
        if (vis[n] == 0) {
            dfs(n)
        }
    }
}
