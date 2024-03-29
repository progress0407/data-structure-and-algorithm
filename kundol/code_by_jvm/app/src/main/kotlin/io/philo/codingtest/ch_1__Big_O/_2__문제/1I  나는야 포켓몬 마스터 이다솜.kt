package io.philo.codingtest.ch_1__Big_O._2__문제

fun main() {

    val (N, M) = readln().split(" ").map { it.toInt() }

    val fn = mutableMapOf<String, Int>()
    val revFn = mutableMapOf<Int, String>()
    repeat(N) { index ->
        val pokeName = readln()
        fn[pokeName] = index + 1
        revFn[index + 1] = pokeName
    }
//    println("--------------")
    repeat(M) {
        val question = readln()
        if (question.toIntOrNull() == null) { // 숫자 X, 문자
            println(fn[question])
        } else {
            println(revFn[question.toInt()])
        }
    }
}