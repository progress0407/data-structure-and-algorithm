package io.philo.codingtest.ch_2__D_BFS._2__문제._2Q_치즈

private val dy = intArrayOf(1, 0, -1, 0)
private val dx = intArrayOf(0, 1, 0, -1)

private var n = 0
private var m = 0

private lateinit var mapp: Array<IntArray>

private var cnt = 0
private var cheeseCnt = 0
private val cheeseCnts = mutableListOf<Int>()

fun main() {
    val inp = readln().split(" ").map { it.toInt() }
    n = inp[0]; m = inp[1]
    mapp = Array(n) { IntArray(m) }

    repeat(n) { index ->
        val nums = readln().split(" ").map { it.toInt() }.toIntArray()
        mapp[index] = nums
    }

    /**
     * 외곽 지역 마킹
     * 0 -> 빈곳
     * 1 -> 치즈
     * 2 -> 외곽 지역
     * 4 -> 없어질 지역
     */
    // 외곽지역 마킹하기
    // 세로줄 2개
    for (y in 0..n - 1) {
        var x = 0
        if (mapp[y][x] == 0)
            dfs(y, x)

        x = m - 1
        if (mapp[y][x] == 0)
            dfs(y, x)
    }

    // 가로줄 2개
    for (x in 0..m - 1) {
        var y = 0
        if (mapp[y][x] == 0)
            dfs(y, x)

        y = n - 1
        if (mapp[y][x] == 0)
            dfs(y, x)
    }

    println("============== 외곽 지역 색칠하기 ==============")
    mapp.forEach { println(it.contentToString()) }


    while (checkCheeseExist()) {
        cnt++
        for (y in 0..n - 1)
            for (x in 0..m - 1)
                for (i in 0..3) {
                    val ny = y + dy[i]
                    val nx = x + dx[i]

                    //인버한 곳이 2라면, 해당 지점(y,x)는 to dead 마킹
                    if (ny in 0..n - 1 && nx in 0..m - 1 &&
                        mapp[ny][nx] == 2 &&
                        mapp[y][x] == 1
                    ) {
                        mapp[y][x] = 4
                    }
                }
        println("============== 마킹 후 ==============")
        mapp.forEach { println(it.contentToString()) }

        // 실제로 없애기
        for (y in 0..n - 1)
            for (x in 0..m - 1)
                if (mapp[y][x] == 4)
                    mapp[y][x] = 2
    }
    val last = cheeseCnts.filter { it == 0 }.last()
    println("cnt = $cnt, lastCheeseCnt = $last")

    println("cheeseCnts = ${cheeseCnts}")
}

private fun dfs(y: Int, x: Int) {

    mapp[y][x] = 2

    for (i in 0..3) {
        val ny = y + dy[i]
        val nx = x + dx[i]

        if (ny in 0..n - 1 && nx in 0..m - 1 && mapp[ny][nx] == 0)
            dfs(ny, nx)
    }
}

private fun checkCheeseExist(): Boolean {
    cheeseCnt = 0

    for (y in 0..n - 1)
        for (x in 0..m - 1)
            if (mapp[y][x] == 1) cheeseCnt++

    cheeseCnts.add(cheeseCnt)

    return if (cheeseCnt > 0) true else false
}
