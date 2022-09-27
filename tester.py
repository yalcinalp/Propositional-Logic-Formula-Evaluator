import os
import sys

if not os.path.isfile("the2.c"):
	sys.exit()

os.system("gcc -Wall -ansi -pedantic-errors the2.c -o the2 -lm")

total_cases = 667
passed_cases = 0

for i in range(0, total_cases):
	with open(f"test/outputs/output{i}.txt", "r") as expected:
		expected_output = expected.read()

	os.system(f"./the2 < test/cases/case{i}.txt > given_output.txt")

	with open("given_output.txt", "r") as given:
		given_output = given.read()

	if given_output == expected_output:
		passed_cases+=1
		print(f"PASSED test case {i}.")

	else:
		print(f"FAILED test case {i}.\n\nExpected Output:\n" + expected_output + "\nGiven Output:\n" + given_output)

os.system("rm -rf given_output.txt")

print("Your Grade:", (passed_cases/total_cases) * 100)
