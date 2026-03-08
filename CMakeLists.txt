cmake_minimum_required(VERSION 3.31)
project(Competitive_Programming)

set(CMAKE_CXX_STANDARD 20)

# --- General ---
add_executable(General_Practice "main.cpp")

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
add_executable(DP_Frog_1 "DP/Problems/Frog_1.cpp")
add_executable(DP_Frog_2 "DP/Problems/Frog_2.cpp")
add_executable(DP_Vacation "DP/Problems/Vacation.cpp")
add_executable(DP_Knapsack_1 "DP/Problems/Knapsack_1.cpp")
add_executable(DP_Knapsack_2 "DP/Problems/Knapsack_2.cpp")
add_executable(DP_Longest_Path "DP/Problems/Longest_Path.cpp")
add_executable(DP_Grid_1 "DP/Problems/Grid_1.cpp")
add_executable(DP_Coins "DP/Problems/Coins.cpp")
add_executable(DP_Deque "DP/Problems/Deque.cpp")
add_executable(DP_Matching "DP/Problems/Matching.cpp")
add_executable(DP_Digit_Sum "DP/Problems/Digit_Sum.cpp")
add_executable(DP_Dice_Combinations "DP/Problems/Dice_Combinations.cpp")
add_executable(DP_Minimizing_Coins "DP/Problems/Minimizing_Coins.cpp")
add_executable(DP_Coin_Combinations_I "DP/Problems/Coin_Combinations_I.cpp")
add_executable(DP_Coin_Combinations_II "DP/Problems/Coin_Combinations_II.cpp")
add_executable(DP_Grid_Paths_I "DP/Problems/Grid_Paths_I.cpp")
add_executable(DP_Book_Shop "DP/Problems/Book_Shop.cpp")
add_executable(DP_Counting_Numbers "DP/Problems/Counting_Numbers.cpp")

# --- DP with Solution Construction ---
add_executable(DP_LCS "DP/DP with Solution Construction/LCS.cpp")
add_executable(DP_Palindromic_Subsequence "DP/DP with Solution Construction/Palindromic_Subsequence.cpp")
add_executable(DP_Changing_a_String "DP/DP with Solution Construction/Changing_a_String.cpp")

# --- Data Structure ---
add_executable(Segment_tree "Data Structure/Segment_tree.cpp"
        "Data Structure/Lazy_Segment_tree.cpp"
        "Data Structure/Sparse_table.cpp"
        "Data Structure/DSU.cpp"
)
