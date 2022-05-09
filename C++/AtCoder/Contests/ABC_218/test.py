# Python code to demonstrate the working of
# zip()

# initializing lists
name = [ [ '#','#','.','.' ],
					[ '#','.','.','.' ],
					[ '.','.','#','.' ],
					[ '.','.','.','.' ] ]
roll_no = [ 4, 1, 3, 2 ]
marks = [ 40, 50, 60, 70 ]

# using zip() to map values
mapped=[]
mapped = list(zip(*name[::-1]))

# converting values to print as set
mapped = set(mapped)

# printing resultant values
print ("The zipped result is : ",end="")
print (mapped)
