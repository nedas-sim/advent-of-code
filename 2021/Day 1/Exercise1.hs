main :: IO ()
main = do
    print (length (filterIncreasing (pairConsecutive depths)))
    

-- Helpers:
printList :: Show a => [a] -> IO ()
printList xs = putStrLn $ show xs


-- Logic:
-- depths: for inputs
depths :: [Int]
depths = [1,2,3,5,4,6]

pairConsecutive :: [Int] -> [(Int, Int)]
pairConsecutive inputList = [(x, y) | (x, y) <- zip inputList (tail inputList)]

filterIncreasing :: [(Int, Int)] -> [(Int, Int)]
filterIncreasing inputList = [(a, b) | (a, b) <- inputList, a < b]