package io.philo.codingtest.ch_2__d_bfs._2__문제._3C_안전영역

private val dy = intArrayOf(1, 0, -1, 0)
private val dx = intArrayOf(0, 1, 0, -1)
private var n = 0
private val cntArr = IntArray(10)

private lateinit var mapp: Array<IntArray>
private lateinit var digitMapp: Array<IntArray>
private lateinit var vis: Array<IntArray>

/**
 * public test code success
 *
 * private test code fail
 */
fun main() {

    n = readln().toInt()
    mapp = Array(n) { IntArray(n) }

    repeat(n) { y ->
        mapp[y] = readln().split(" ").map { it.toInt() }.toIntArray()
    }

//    mapp.forEach { println(it.contentToString()) }

    for (rainHeight in 1..9) {

        digitMapp = Array(n) { IntArray(n) { 1 } }
        vis = Array(n) { IntArray(n) }

        for (y in 0..n - 1) {
            for (x in 0..n - 1) {
                val regionHeight = mapp[y][x]
                if (regionHeight <= rainHeight) {
                    digitMapp[y][x] = 0
                }
            }
        }

//        println("------------------------------")
//        digitMapp.forEach { println(it.contentToString()) }

        // connected component
        var cnt = 0
//        println("## rain Height: $rainHeight")
//        digitMapp.forEach { println(it.contentToString()) }
        for (y in 0..n - 1) {
            for (x in 0..n - 1) {
                if (digitMapp[y][x] == 1 && vis[y][x] == 0) {
                    cnt++
//                    println("cc found : ($y, $x)")
                    dfs(y, x)
                }
            }
        }
        cntArr[rainHeight] = cnt
    }

//    println("cntArr = ${cntArr.contentToString()}")
//    println("cntArr.max() = ${cntArr.max()}")
    println(cntArr.max())
}

private fun dfs(y: Int, x: Int) {

    vis[y][x] = 1
//    println("vis = ($y, $x)")

    for (i in 0..3) {
        val ny = y + dy[i]
        val nx = x + dx[i]

        if (ny in 0..n - 1 &&
            nx in 0..n - 1 &&
            digitMapp[ny][nx] == 1 &&
            vis[ny][nx] == 0
        ) {
            dfs(ny, nx)
        }
    }
}
