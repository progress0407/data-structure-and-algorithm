package io.philo.codingtest.ch_1__big_o._2__문제

/**
 * 두뇌의 한계가 느껴진다...
 *
 * 그림을 이용하자...
 *
 * 첨자 확인 잘하기 (시작 & 끝수)
 */
fun main() {

    val (N, K) = readln().split(" ").map { it.toInt() }


    val intList = readln().split(" ").map { it.toInt() }

    // 원 수열
    val arr = intList.toIntArray()

    // 합 수열
    val sumArr = Array(N) { 0 }

    sumArr[0] = arr[0]
    for (i in 1..N - 1) {
        sumArr[i] = sumArr[i - 1] + arr[i]
    }

    // 부분합 수열
    val rangedSumArr = Array<Int>(N) { 0 }

    // 첫항
    rangedSumArr[K - 1] = sumArr[K - 1]

    // 나머지
    for (x in K..N - 1) {
        rangedSumArr[x] = sumArr[x] - sumArr[x - K]
    }

//    println("rangedSumArr = ${rangedSumArr.contentToString()}")
    val resResult = rangedSumArr.filterIndexed { index, value -> (index >= K - 1) }.toList()

    println(resResult.max())
}
