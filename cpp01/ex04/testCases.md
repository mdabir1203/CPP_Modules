
# Let's dive into some quirky scenarios to test our replace function / sed :

##
Create a test file with multiple occurrences of "s1" and pass it, along with "s1" and "s2," to the replace function. Verify that the output file contains the replaced occurrences of "s1" with "s2."
##
Pass a nonexistent file name to the replace function and ensure it displays an error message indicating the input file couldn't be opened.
##
Test the replace function with "s1" and "s2" strings of different lengths. Create a test file with occurrences of "s1" and verify that the output file correctly replaces "s1" with "s2" considering the length difference.
##
Test the replace function with empty strings for "s1" and "s2." Create a test file and check that the output file is an exact copy, with no replacements.
##
Test the replace function with an empty input file. Ensure that the output file is also empty, indicating no replacements were made.
##
Create a test file without any occurrences of "s1" and pass it to the replace function. Verify that the output file remains unchanged, matching the input file.
##
Test the replace function with special characters or whitespace in "s1" and "s2." Create a test file with such content and verify that the output file accurately replaces "s1" with "s2," considering the special characters or whitespace.
##
Evaluate the replace function's performance and memory usage using a large input file. Measure execution time, monitor memory, and ensure the output file contains accurate replacements for "s1" with "s2."




