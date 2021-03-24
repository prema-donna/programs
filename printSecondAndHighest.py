import sys

def printSecondHighestAndHighestFunction(listOne):
  secondLargest = -sys.maxsize-1
  largest = -sys.maxsize-1
  for value in listOne:
    if value > secondLargest and value < largest:
      secondLargest = value
    if value > largest:
      secondLargest = largest
      largest = value
  print("Second largest number {}".format(secondLargest))
  print("Largest number {}".format(largest))

printSecondHighestAndHighestFunction([10, 20, 4, 45, 99, 46, 98, 2, 102, -5])
