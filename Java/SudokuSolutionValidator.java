public class SudokuValidator {
    public static boolean check(int[][] sudoku) {
        
      for(int i=0; i<sudoku[0].length; ++i)
      {

        boolean s1 = checkRow(sudoku[i], 0);
        boolean s2 = checkColumn(sudoku, i, 0);
        if(!s1 || !s2)
          return false; 
      }
      
      return checkSubGrids(sudoku);
    }
  
  private static boolean checkColumn(int [][] arr, int col_index, int row_index)
  {
    int num = arr[row_index][col_index];
    if( num == 0)
      return false;

    
    for(int i=row_index + 1; i< arr.length; ++i)
    {
        if(arr[i][col_index] == num || arr[i][col_index] == 0)
          return false;
    }
    
    return true;
  }
  
  private static boolean checkRow(int[] row, int index)
  {
    if(row[index] == 0)
      return false;
    int num = row[index];
    
    for(int i=index + 1; i<row.length; ++i)
      {
      if(num == row[i] ||row[i] == 0)
        return false;
      }
    
    return true;
  }
  
  private static boolean checkSubGrids(int [][] sudoku) 
  {
    
    for(int i=0; i<sudoku.length; i += 3)
    {
      for(int j=0;j<sudoku[i].length; j += 3)
      {
        for(int num = 1; num<=9; ++num)
        {
          boolean found = false;
          for(int z=i; z<i+3; ++z)
          {
            if(rowOfSubGroupContains(sudoku[z], j, num))
              found = true;
          }
          if(!found)
            return false;
        }
      }
    }
    
    return true;
  }
  
  
  private static boolean rowOfSubGroupContains(int [] row, int startIndex, int number)
  {
    
    for(int i=startIndex; i < startIndex+3; ++i)
      if(row[i] == number)
        return true;

    return false;
  }
  
  
}
