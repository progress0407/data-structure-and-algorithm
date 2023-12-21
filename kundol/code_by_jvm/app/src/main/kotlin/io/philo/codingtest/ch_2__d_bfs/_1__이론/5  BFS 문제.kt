package io.philo.codingtest.ch_2__d_bfs._1__이론

import java.util.LinkedList

//private var dy = intArrayOf(1, 0, -1, 0)
//private var dx = intArrayOf(0, 1, 0, -1)
private var ds = arrayOf(
    Point(1, 0),
    Point(-1, 0),
    Point(0, 1),
    Point(0, -1)
)

private lateinit var mapp: Array<IntArray>
private lateinit var vis: Array<IntArray>

/**
 * 맵 크기  세로 가로
 *
 * 처음 위치 y x
 *
 * 목표 위치 y x
 */

private var my: Int = 0
private var mx: Int = 0

private var sy: Int = 0
private var sx: Int = 0

private var ey: Int = 0
private var ex: Int = 0

fun main() {

    val inp1 = readln().split(" ").map { it.toInt() }
    my = inp1[0]; mx = inp1[1]

    val inp2 = readln().split(" ").map { it.toInt() }
    sy = inp2[0]; sx = inp2[1]

    val inp3 = readln().split(" ").map { it.toInt() }
    ey = inp3[0]; ex = inp3[1]

    mapp = Array(my) { IntArray(mx) }
    vis = Array(my) { IntArray(mx) }

    repeat(my) { y ->
        mapp[y] = readln().split(" ").map { it.toInt() }.toIntArray()
    }

    mapp.forEach { println(it.contentToString()) }

    val queue = LinkedList<Point>()
    queue.add(Point(sy, sx))
    vis[sy][sx] = 1

    while (queue.isNotEmpty()) {
        val here = queue.poll()
        println("here = ${here}")
        for (d in ds) {
//            val ny = here.y + dy[i]
//            val nx = here.x + dx[i]
            val n = here + d
            if (n.y in 0..my - 1 &&
                n.x in 0..mx - 1 &&
                mapp[n.y][n.x] == 1 &&
                vis[n.y][n.x] == 0
            ) {
                vis[n.y][n.x] = vis[here.y][here.x] + 1
                queue.add(n)
            }
        }
    }

    println("vis[ey][ex] = ${vis[ey][ex]}")
    vis.forEach { println(it.contentToString()) }
}

data class Point(val y: Int, val x: Int) {


    operator fun plus(other: Point): Point {
        return Point(this.y + other.y, this.x + other.x)
    }
}




































