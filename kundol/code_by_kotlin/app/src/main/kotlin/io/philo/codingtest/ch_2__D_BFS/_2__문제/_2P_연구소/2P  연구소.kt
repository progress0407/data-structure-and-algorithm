package io.philo.codingtest.ch_2__D_BFS._2__문제._2P_연구소

private lateinit var originMapp: Array<IntArray>
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

    input()
    val wallList = getWallest()

    var areas = mutableListOf<Int>()
    var buildWallCnt = 0
    for (wall in wallList) {

        val (w1, w2, w3) = wall
        val (w1y, w1x) = w1
        val (w2y, w2x) = w2
        val (w3y, w3x) = w3

        if (mapp[w1y][w1x] == 0 && mapp[w2y][w2x] == 0 && mapp[w3y][w3x] == 0) {

            buildWallCnt++

            // 벽 심기
            mapp[w1y][w1x] = 1
            mapp[w2y][w2x] = 1
            mapp[w3y][w3x] = 1

            // 바이러스 퍼뜨리기 (dfs 돌리기)
            for (y in 0..n - 1)
                for (x in 0..m - 1)
                    if (mapp[y][x] == 2) {
                        dfs(y, x)
                    }

            // 면적 세기
            var area = 0
            for (y in 0..n - 1)
                for (x in 0..m - 1)
                    if (mapp[y][x] == 0) area++

            areas.add(area)

            // 초기화
            mapp = originMapp.map { it.clone() }.toTypedArray()
        }
    }

    val maxArea = areas.max()
    println(maxArea)
}

private fun input() {
    val inp = readln().split(" ").map { it.toInt() }
    n = inp[0]; m = inp[1]

    mapp = Array(n) { IntArray(m) }
    originMapp = Array(n) { IntArray(m) }

    repeat(n) { y ->
        val numList = readln().split(" ").map { it.toInt() }.toIntArray()
        originMapp[y] = numList
    }
    mapp = originMapp.map { it.clone() }.toTypedArray()
}

private fun getWallest(): MutableList<Triple<Pair<Int, Int>, Pair<Int, Int>, Pair<Int, Int>>> {
    val semiCombis = mutableListOf<Triple<Int, Int, Int>>()
    val totalCellCnt = n * m
    for (i in 0..totalCellCnt - 3) {
        for (j in i + 1..totalCellCnt - 2) {
            for (k in j + 1..totalCellCnt - 1) {
                semiCombis.add(Triple(i, j, k))
            }
        }
    }

    val wallList = mutableListOf<Triple<Pair<Int, Int>, Pair<Int, Int>, Pair<Int, Int>>>()

    for (origin in semiCombis) {
        val (a, b, c) = origin
        val converted = Triple(Pair(a / m, a % m), Pair(b / m, b % m), Pair(c / m, c % m))
        wallList.add(converted)
    }
    return wallList
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