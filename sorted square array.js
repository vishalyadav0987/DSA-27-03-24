/**
 * @param {number[]} nums
 * @return {number[]}
 */
var sortedSquares = function (nums) {
    // return nums.map((val)=>val * val).sort((a,b)=>a-b);
    const sortedArray = nums.map((val) => {
        return val * val
    });
    return sortedArray.sort((a, b) => a - b);
};