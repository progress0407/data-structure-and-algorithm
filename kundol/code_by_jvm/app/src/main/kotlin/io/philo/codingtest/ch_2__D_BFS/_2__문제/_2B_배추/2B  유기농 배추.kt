package io.philo.codingtest.ch_2__D_BFS._2__문제._2B_배추

/**
 * t: 테스트 케이스
 *
 * m: 가로 길이
 *
 * n: 세로 길이
 *
 * k: 배추 위치 갯수
 *
 *
 * x: 가로 위치
 *
 * y: 세로 위치
 */

private val dy = intArrayOf(1, 0, -1, 0)
private val dx = intArrayOf(0, 1, 0, -1)

private lateinit var mapp: Array<IntArray>
private lateinit var vis: Array<IntArray>

private var m: Int = 0
private var n: Int = 0
private var k: Int = 0

fun main() {

    val t = readln().toInt()

    repeat(t) { index ->

        val inp = readln().split(" ").map { it.toInt() }
        m = inp[0]
        n = inp[1]
        k = inp[2]

        mapp = Array(n) { IntArray(m) }
        vis = Array(n) { IntArray(m) }

        repeat(k) {
            val (x, y) = readln().split(" ").map { it.toInt() }
            mapp[y][x] = 1
        }

        /**
         * y, n  세로
         *
         * x, m  가로
         */
        var cnt = 0
        for (y in 0..n - 1) {
            for (x in 0..m - 1) {
                if (mapp[y][x] == 1 && vis[y][x] == 0) {
                    cnt++
//                    println("cnt start -> ($y, $x)")
                    dfs(y, x)
                }
            }
        }
        println(cnt)
    }
}

private fun dfs(y: Int, x: Int) {

    vis[y][x] = 1
//    println("vis -----------> ($y, $x)")

    for (i in 0..3) {

        val ny = y + dy[i]
        val nx = x + dx[i]

        if (ny in 0..n - 1 &&
            nx in 0..m - 1 &&
            mapp[ny][nx] == 1 &&
            vis[ny][nx] == 0
        ) {
            dfs(ny, nx)
        }
    }
}
