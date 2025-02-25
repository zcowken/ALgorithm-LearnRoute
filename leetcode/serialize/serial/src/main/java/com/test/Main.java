package com.test;

import com.google.gson.Gson;
import com.google.gson.reflect.TypeToken;

import java.lang.reflect.Type;
import java.util.List;

public class Main {

    static void convert2DListToArrayString(List<List<Integer>> list2D) {
        System.out.print("{");
        for (List<Integer> row : list2D) {
            System.out.print("{");
            for (int i2 = 0; i2 < row.size(); i2++) {
                int num = row.get(i2);
                System.out.print(num);

                if (i2 != row.size() - 1) {
                    System.out.print(", ");

                }

            }
            System.out.print("}");
        }
        System.out.print("}");
    }

    public static void main(String[] args) {
        Gson gson = new Gson();
        String json = "[[1,2,3],[4,5,6],[7,8,9]]";
        // 定义列表类型
        Type listType = new TypeToken<List<List<Integer>>>() {
        }.getType();

        // 转换为 List<List<Integer>>
        List<List<Integer>> list2D = gson.fromJson(json, listType);

        // 验证结果
        for (List<Integer> row : list2D) {
            for (Integer num : row) {
                System.out.print(num + " ");
            }
            System.out.println();
        }

        convert2DListToArrayString(list2D);

    }
}