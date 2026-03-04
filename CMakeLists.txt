cmake_minimum_required(VERSION 3.31)
project(Competitive_Programming)

set(CMAKE_CXX_STANDARD 20)

# --- Assuit Recursion Sheet ---
add_executable(Problem_A "Assuit_Recursion/A_Print_Recursion.cpp")
add_executable(Problem_B "Assuit_Recursion/B_Print_from_1_to_N.cpp")
add_executable(Problem_C "Assuit_Recursion/C_Print_from_N_to_1.cpp")
add_executable(Problem_D "Assuit_Recursion/D_Print_Digits_using_Recursion.cpp")
add_executable(Problem_E "Assuit_Recursion/E_Base_Converssion.cpp")
add_executable(Problem_F "Assuit_Recursion/F_Print_Even_Indices.cpp")
add_executable(Problem_G "Assuit_Recursion/G_Pyramid.cpp")
add_executable(Problem_H "Assuit_Recursion/H_Inverted_Pyramid.cpp")
add_executable(Problem_I "Assuit_Recursion/I_Count_Vowels.cpp")
add_executable(Problem_J "Assuit_Recursion/J_Factorial.cpp")
add_executable(Problem_K "Assuit_Recursion/K_Max_Number.cpp")
add_executable(Problem_L "Assuit_Recursion/L_Summation.cpp")
add_executable(Problem_M "Assuit_Recursion/M_Suffix_Sum.cpp")
add_executable(Problem_N "Assuit_Recursion/N_Sum_of_a_Matrix.cpp")
add_executable(Problem_O "Assuit_Recursion/O_Fibonacci.cpp")
add_executable(Problem_P "Assuit_Recursion/P_Log2.cpp")
add_executable(Problem_Q "Assuit_Recursion/Q_3n_Plus_1_Sequence.cpp")
add_executable(Problem_R "Assuit_Recursion/R_Palindrome_Array.cpp")
add_executable(Problem_S "Assuit_Recursion/S_Array_Average.cpp")
add_executable(Problem_T "Assuit_Recursion/T_Combination.cpp")
add_executable(Problem_U "Assuit_Recursion/U_Knapsack.cpp")
add_executable(Problem_V "Assuit_Recursion/V_Creating_Expression1.cpp")
add_executable(Problem_W "Assuit_Recursion/W_Reach_Value.cpp")
add_executable(Problem_X "Assuit_Recursion/X_The_maximum_path_sum.cpp")
add_executable(Problem_Y "Assuit_Recursion/Y_Number_of_Ways.cpp")
add_executable(Problem_Z "Assuit_Recursion/Z_Left_Max.cpp")

# --- Dynamic Programming (DP) ---
add_executable(DP_Frog_1 "DP/Problems/Frog_1.cpp"
        DP/Problems/Knapsack_1.cpp
        DP/Problems/Knapsack_2.cpp
)
add_executable(DP_Frog_2 "DP/Problems/Frog_2.cpp")
add_executable(DP_Vacation "DP/Problems/Vacation.cpp")
add_executable(DP_Knapsack_1 "DP/Problems/Knapsack_1.cpp")
add_executable(DP_Knapsack_2 "DP/Problems/Knapsack_2.cpp")