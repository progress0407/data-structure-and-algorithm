package io.philo.codingtest.ch_0__basic._1__이론

class _0__재귀

fun main() {

//    val result = factorial(5)
//    println("result = ${result}")

    println(fibo(5))
}

fun factorial(n: Int): Int {

    require(n >= 0) {
        "n은 음수가 될 수 없습니다"
    }

    return if (n == 1 || n == 0) 1
    else n * factorial(n - 1)
}

fun fibo(n: Int): Int {

    require(n >= 1) {
        "n은 양수여야 합니다"
    }

    return if (n in 1..2) 1
    else fibo(n - 1) + fibo(n - 2)
}