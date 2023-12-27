package io.philo.codingtest.ch_2__D_BFS._2__문제._2P_연구소

private lateinit var mapp: Array<IntArray>

/**
 * 0 빈칸
 *
 * 1 벽
 *
 * 2 바이러스
 */
private val dy = intArrayOf(1, 0, -1, 0)
private val dx = intArrayOf(0, 1, 0, -1)
private var n = 0
private var m = 0

fun main() {

    val inp = readln().split(" ").map { it.toInt() }
    n = inp[0]; m = inp[1]

    mapp = Array(n) { IntArray(m) }

    repeat(n) { y ->
        val numList = readln().split(" ").map { it.toInt() }.toIntArray()
        mapp[y] = numList
    }

    val (w1y, w1x) = Pair(1, 0)
    val (w2y, w2x) = Pair(0, 1)
    val (w3y, w3x) = Pair(3, 5)

    // 벽 심기
    mapp[w1y][w1x] = 1
    mapp[w2y][w2x] = 1
    mapp[w3y][w3x] = 1

    println("## 벽 심어~")
    mapp.forEach { println(it.contentToString()) }

    // 바이러스 퍼뜨리기 (dfs 돌리기)
    for (y in 0..n - 1)
        for (x in 0..m - 1)
            if (mapp[y][x] == 2) {
                dfs(y, x)
            }

    println("## 바이러스 심어~")
    mapp.forEach { println(it.contentToString()) }

    // 면적 세기
    var area = 0
    for (y in 0..n - 1)
        for (x in 0..m - 1)
            if (mapp[y][x] == 0) area++

    println("area = ${area}")
}

private fun dfs(y: Int, x: Int) {

    for (i in 0..3) {

        val ny = y + dy[i]
        val nx = x + dx[i]

        if (ny in 0..n - 1 && nx in 0..m - 1 && mapp[ny][nx] == 0) {
            mapp[ny][nx] = 2
            dfs(ny, nx)
        }
    }
}