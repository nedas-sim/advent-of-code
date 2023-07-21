main :: IO ()
main = do
    print (length (filterIncreasing (pairConsecutive (sumTuples (groupSlidingWindows depths)))))
    

-- Helpers:
printList :: Show a => [a] -> IO ()
printList xs = putStrLn $ show xs


-- Logic:
-- depths: for inputs
depths :: [Int]
depths = [1,2,3,5,4,6]

groupSlidingWindows :: [Int] -> [(Int, Int, Int)]
groupSlidingWindows inputList = [(x, y, z) | ((x, y), z) <- zip (zip inputList (tail inputList)) (tail (tail inputList))]

sumTuples :: [(Int, Int, Int)] -> [Int]
sumTuples inputList = [x + y + z | (x, y, z) <- inputList]

pairConsecutive :: [Int] -> [(Int, Int)]
pairConsecutive inputList = [(x, y) | (x, y) <- zip inputList (tail inputList)]

filterIncreasing :: [(Int, Int)] -> [(Int, Int)]
filterIncreasing inputList = [(a, b) | (a, b) <- inputList, a < b]