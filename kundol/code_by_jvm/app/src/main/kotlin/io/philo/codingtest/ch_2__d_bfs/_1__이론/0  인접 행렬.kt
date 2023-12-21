package io.philo.codingtest.ch_2__d_bfs._1__이론

fun main() {
    /*
        val a = arrayOf(
            booleanArrayOf(false, true, true, true),
            booleanArrayOf(true, false, true, false),
            booleanArrayOf(true, true, false, false),
            booleanArrayOf(true, false, false, false)
        )
    println(a[0][0])
    */

    // 인접 행렬
    val (arr, visArr) = `2D Rectangle Array`(10) // 0 ~ 9 정사각형
    arr.mapEachOther(1, 2)
    arr.mapEachOther(1, 3)
    arr.mapEachOther(3, 4)

    arr.print()

    arr.visit(1, visArr)
}

private fun `2D Rectangle Array`(x: Int): Pair<Array<IntArray>, IntArray> {
    val array: Array<IntArray> = Array(x) { IntArray(x) { 0 } }
    val visArr: IntArray = IntArray(x)
    return Pair<Array<IntArray>, IntArray>(array, visArr)
}

private fun Array<IntArray>.mapEachOther(x: Int, y: Int) {

    this[x][y] = 1
    this[y][x] = 1
}

private fun Array<IntArray>.print() {
    this.forEach {
        println(it.contentToString())
    }
}

private fun Array<IntArray>.visit(x: Int, visArr: IntArray) {

    val n = this.size
    visArr[x] = 1
    println(x)

    for (next in 0..n - 1) {
        if (next == x) continue
        // 길이 있고, 아직 방문 안한 곳
        if (this[next][x] == 1 && visArr[next] == 0) {
            this.visit(next, visArr)
        }
    }
}
