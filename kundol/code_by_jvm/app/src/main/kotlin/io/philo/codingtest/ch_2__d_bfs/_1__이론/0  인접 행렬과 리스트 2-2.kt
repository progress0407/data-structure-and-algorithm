package io.philo.codingtest.ch_2__d_bfs._1__이론

fun main() {
//    `인접 리스트 샘플 구현`()
    `인접 리스트 탐색 구현`()
}

private fun `인접 리스트 탐색 구현`() {

    /**
     * 정점은 0번 부터 9번까지 10개의 노드가 있다. 1 - 2 /  1 - 3 / 3 - 4 라는 경로가 있다. (1번과 2번, 1번과 3번, 3번과 4번은 연결되어있다.)
     *
     * 이를 인접리스트로 표현한다면?
     */

    val v = 10
    val adj = Array<MutableList<Int>>(v) { mutableListOf() }

    adj[1].addAll(listOf(2, 3))
    adj[2].addAll(listOf(1))
    adj[3].addAll(listOf(1, 4))
    adj[4].addAll(listOf(3))

    // 방문, 1부터
    val vis = IntArray(v)
    visit(adj, vis, 1)
}

private fun visit(adj: Array<MutableList<Int>>, vis: IntArray, point: Int) {

    vis[point] = 1
    println(point)

    for (list in adj) {
        for (n in list) {
            if (vis[n] == 0) {
                visit(adj, vis, n)
            }
        }
    }
}

private fun `인접 리스트 샘플 구현`() {

    val v = 4

    val adj = Array<MutableList<Int>>(v) { mutableListOf() }

    adj[0].addAll(listOf(1, 2, 3))
    adj[1].addAll(listOf(0, 2))
    adj[2].addAll(listOf(0, 1))
    adj[3].addAll(listOf(0))

    for (i in adj.indices) {
        println("i=$i  adj=${adj[i]}")
    }

    println("----------------")

    adj.forEachIndexed { index, values ->
        print("$index : ")
        println(values.joinToString(", "))
    }
}
