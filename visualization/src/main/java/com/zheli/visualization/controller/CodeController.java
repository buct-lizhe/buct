package com.zheli.visualization.controller;

import com.alibaba.fastjson.JSONArray;
import com.alibaba.fastjson.JSONObject;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.autoconfigure.EnableAutoConfiguration;
import org.springframework.web.bind.annotation.*;

import java.io.*;
import java.util.*;

@EnableAutoConfiguration
@RestController
@CrossOrigin
@RequestMapping("/code")
public class CodeController {

    @GetMapping("/getCode")
    public Map<String, Object> getCode() {
        //System.out.println("进入方法！！！");
        JSONObject jsonObject = null;
        HashMap<String, Object> map = new HashMap<>();
        String jsonStr = "";
        try {
            File jsonFile = new File("D:\\graduateCode\\可视化\\codeshow\\public\\data\\pycode.json");
//            System.out.println( jsonFile );
            FileReader fileReader = new FileReader(jsonFile);
            Reader reader = new InputStreamReader(new FileInputStream(jsonFile), "utf-8");
            int ch = 0;
            StringBuffer sb = new StringBuffer();
            while ((ch = reader.read()) != -1) {
                sb.append((char) ch);
            }
            fileReader.close();
            reader.close();
            jsonStr = sb.toString();
            JSONArray jos = JSONArray.parseArray(jsonStr);
//            System.out.println( jos );
            jsonObject = (JSONObject) jos.getJSONObject(0);
//            System.out.println( jsonObject );
        } catch (IOException e) {
            e.printStackTrace();
            return null;
        }

        int sum_index = 0;
        try {
            File jsonFile = new File("D:\\graduateCode\\可视化\\codeshow\\public\\data\\detailvalue.json");
//            System.out.println( jsonFile );
            FileReader fileReader = new FileReader(jsonFile);
            Reader reader = new InputStreamReader(new FileInputStream(jsonFile), "utf-8");
            int ch = 0;
            StringBuffer sb = new StringBuffer();
            while ((ch = reader.read()) != -1) {
                sb.append((char) ch);
            }
            fileReader.close();
            reader.close();
            jsonStr = sb.toString();
            System.out.println( jsonStr );
            JSONObject jos = JSONObject.parseObject(jsonStr);
            sum_index = (int) jos.get("sum_index");
        }catch (IOException e) {
            e.printStackTrace();
            return null;
        }

        map.put("codes", jsonObject);
        map.put("sum_index" , sum_index );
        return map;
    }

    @GetMapping("/getVarValue")
    public Map<String, Object> getVarValue(int index) {
        //System.out.println("进入方法！！！");
        JSONObject jsonObject = null;
        HashMap<String, Object> map = new HashMap<>();
        String jsonStr = "";
        JSONArray jsonArray1 = new JSONArray();
        int[] firstIndex = new int[100000 + 100];
        int firstIndexCount = 0;
        try {
            File jsonFile = new File("D:\\graduateCode\\可视化\\codeshow\\public\\data\\varvalue.json");
//            System.out.println( jsonFile );
            FileReader fileReader = new FileReader(jsonFile);
            Reader reader = new InputStreamReader(new FileInputStream(jsonFile), "utf-8");
            int ch = 0;
            StringBuffer sb = new StringBuffer();
            while ((ch = reader.read()) != -1) {
                sb.append((char) ch);
            }
            fileReader.close();
            reader.close();
            jsonStr = sb.toString();
            JSONArray jos = JSONArray.parseArray(jsonStr);
//            System.out.println( jos );
            jsonObject = (JSONObject) jos.getJSONObject(0);
            jsonObject = jsonObject.getJSONObject("info");
//            System.out.println(jsonObject);
            for (Map.Entry<String, Object> entry : jsonObject.entrySet()) {
                JSONObject jsonObject1 = new JSONObject();
//                System.out.println("key值="+entry.getKey());
//                System.out.println("value="+(List)entry.getValue());
                JSONArray jsonArray = (JSONArray) entry.getValue();
                int index1 = -1;
                for (int i = jsonArray.size() - 1; i > 0; i--) {   //从后往前找
                    if (Integer.parseInt(jsonArray.getJSONObject(i).get("index").toString()) <= index) {
                        //寻找到运行到index行，变量最新的取值   ？？？递归回溯情况如何解决？？？
                        jsonObject1.put("varName", entry.getKey());
                        jsonObject1.put("varValue", jsonArray.getJSONObject(i).get("value").toString());
                        jsonObject1.put("index", jsonArray.getJSONObject(i).get("index").toString());
                        int firstIndexValue = Integer.parseInt(jsonArray.getJSONObject(0).get("firstindex").toString());
                        firstIndex[firstIndexCount++] = firstIndexValue;
                        jsonArray1.add(jsonObject1);
//                        System.out.println( entry.getKey() + "  " + jsonArray.getJSONObject(i).get("index").toString() );
                        break;
                    }
                }
            }
//            System.out.println( jsonArray1 );
//            System.out.println( jsonObject.get("a") );
        } catch (IOException e) {
            e.printStackTrace();
            return null;
        }
        JSONArray jsonArray2 = new JSONArray();
//        System.out.println( jsonArray2 );
        Map<Integer, ArrayList> mapIndex = new HashMap<>();  //记录行号和json的index

        for (int i = 0; i < firstIndexCount; i++) {   //解决同一行定义多个变量的问题
//            System.out.println(firstIndex[i]);
            ArrayList<Integer> arrayList = new ArrayList();
            if (mapIndex.get(firstIndex[i]) == null) {
                arrayList.add(i);
                mapIndex.put(firstIndex[i], arrayList);
            } else {
                arrayList = mapIndex.get(firstIndex[i]);
                arrayList.add(i);
                mapIndex.put(firstIndex[i], arrayList);
            }
        }
        Arrays.sort(firstIndex, 0, firstIndexCount);
        Map<Integer, Integer> isVisitIndex = new HashMap<>();
        for (int i = 0; i < firstIndexCount; i++) {
            if (isVisitIndex.get( firstIndex[i] ) == null ) {
                //            System.out.println( firstIndex[i] );
                ArrayList<Integer> arrayList = new ArrayList();
                arrayList = mapIndex.get(firstIndex[i]); //获得行号对应的index序列
                for (int j = 0; j < arrayList.size(); j++) {
//                    System.out.println(arrayList.get(j) + " j= " + j);
                    JSONObject jsonObject1 = jsonArray1.getJSONObject(arrayList.get(j));
                    jsonArray2.add(jsonObject1);
                }
               isVisitIndex.put( firstIndex[i] ,1 );
            }
        }
        System.out.println(jsonArray2);
        map.put("vars", jsonArray2);
        return map;
    }


    @GetMapping("/getDeatilOp")
    public Map<String, Object> getDeatilOp() {
        //System.out.println("进入方法！！！");
        JSONObject jsonObject = null;
        HashMap<String, Object> map = new HashMap<>();
        String jsonStr = "";
        int sum_index = 0;
        JSONObject jo;
        try {
            File jsonFile = new File("D:\\graduateCode\\可视化\\codeshow\\public\\data\\detailvalue.json");
//            System.out.println( jsonFile );
            FileReader fileReader = new FileReader(jsonFile);
            Reader reader = new InputStreamReader(new FileInputStream(jsonFile), "utf-8");
            int ch = 0;
            StringBuffer sb = new StringBuffer();
            while ((ch = reader.read()) != -1) {
                sb.append((char) ch);
            }
            fileReader.close();
            reader.close();
            jsonStr = sb.toString();
            System.out.println( jsonStr );
            jo = JSONObject.parseObject(jsonStr);
        }catch (IOException e) {
            e.printStackTrace();
            return null;
        }
        map.put("detailOps" , jo );
        return map;
    }

    public static void main(String[] args) {
        CodeController codeController = new CodeController();
//        codeController.getCode();
//        codeController.getVarValue(10);
        codeController.getDeatilOp();
    }
}
