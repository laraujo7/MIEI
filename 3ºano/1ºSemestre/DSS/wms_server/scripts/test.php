<?php
    $servername = "remotemysql.com:3306";
    $username = "z0nH5RtMiu";
    $password = "Qq41zMTAn4";
    $dbname = "z0nH5RtMiu";


    // $servername = "25.79.51.218:3306";
    // $username = "root";
    // $password = "g21";
    // $dbname = "z0nH5RtMiu";

    // Create connection
    $conn = new mysqli($servername, $username, $password, $dbname);
    mysqli_set_charset($conn, 'utf8');
    $received_data = json_decode(file_get_contents("php://input"));
    $data = array();


    // Check connection
    if ($conn->connect_error) {
      die("Connection failed: " . $conn->connect_error);
      echo error;
    } else {
        if($received_data->action == 'fetchall') {
            $result = $conn->query("SELECT Product, IDPallet, Quantity AS 'Available' FROM `Pallet`");

            while($row = $result->fetch_assoc()){

                  $data[] =  array(
                    "Name" => $row["Product"],
                    "Reference" => $row["IDPallet"],
                    "Available" => (int)$row["Available"],
                    "Checked" => false,
                    "Quantity" => 0
                  );

            }
            echo json_encode($data,JSON_UNESCAPED_SLASHES);
        }


        if($received_data->action == 'request') {

            //$result = $conn->query(
            //    "SELECT DISTINCT IDRequest FROM Request ORDER BY IDRequest DESC Limit 1 "
            //);
            //$row = $result->fetch_assoc();
            //$new_id = (empty($row) ? 1 : ((int)$row["IDRequest"])+1);
            //echo $new_id;

            $deu = true;

            for ($i=0; $i <  sizeof($received_data->data); $i++) {
                $reference = $received_data->data[$i]->Reference;
                $quantity = $received_data->data[$i]->Quantity;

                $sql = "INSERT INTO JobRobot (Pallet, Station, Status)
                    VALUES ('$reference', '2', 'WAITING')";
                    if ($conn->query($sql) === TRUE) {
                    } else {
                      echo "Error: " . $sql . "<br>" . $conn->error;
                    }
            }
            echo $deu;

            
        }

        // VALUES ($new_id, $received_data->data[$i]->Reference, $received_data->data[$i]->Quantity)

        if($received_data->action == 'filter_name') {

            $result = $conn->query("SELECT Product, Company, SUM(Quantity) AS 'Available' FROM `Pallet` WHERE Product LIKE '%$received_data->data%' GROUP BY Product, Company ");

            while($row = $result->fetch_assoc()) {

                  $data[] =  array(
                    "Name" => $row["Product"],
                    "Company" => $row["Company"],
                    "Available" => (int)$row["Available"],
                    "Checked" => false,
                    "Quantity" => 0
                  );

            }
            echo json_encode($data,JSON_UNESCAPED_SLASHES);

        }


        

        
    }
    $conn -> close();
    

    // while($row =mysqli_fetch_assoc($result))
    // {
    //    $info[] = json_encode($row);
    // }
    // echo json_encode($info);

    exit;
?>


<!-- if($received_data->action == 'fetchall') {
            $result = $conn->query("SELECT Name, IDProduct, Stock FROM Product");
            // echo "[";
            // while ($row = $result->fetch_assoc()) {
            //     $row_name = $row["Name"];
            //     $row_id = $row["IDProduct"];
            //     $row_stock = $row["Stock"];
            //     echo "{Name:'$row_name', Reference:$row_id, Available:$row_stock, Checked: false, Quantity: 0},";
            // }
            // echo "]";

            while($row = $result->fetch_assoc()){
                //$info[] = json_encode($row,JSON_UNESCAPED_SLASHES);

                  $data[] =  array(
                    "Name" => $row["Name"],
                    "Reference" => $row["IDProduct"],
                    "Available" => (int)$row["Stock"],
                    "Checked" => false,
                    "Quantity" => 0
                  );

            }
            echo json_encode($data,JSON_UNESCAPED_SLASHES);
        } -->





     <!--            if($received_data->action == 'request') {

            $result = $conn->query(
                "SELECT DISTINCT IDRequest FROM Request ORDER BY IDRequest DESC Limit 1 "
            );
            $row = $result->fetch_assoc();
            $new_id = (empty($row) ? 1 : ((int)$row["IDRequest"])+1);
            //echo $new_id;

            $deu = true;

            for ($i=0; $i <  sizeof($received_data->data); $i++) {
                $product = $received_data->data[$i]->Name;
                $company = $received_data->data[$i]->Company;
                $quantity = $received_data->data[$i]->Quantity;

                $sql = "INSERT INTO Request (IDRequest, Product, Reference, Quantity)
                    VALUES ($new_id, '$product', '$company', $quantity)";
                    if ($conn->query($sql) === TRUE) {
                    } else {
                      echo "Error: " . $sql . "<br>" . $conn->error;
                    }
            }
            echo $deu;

            
        } -->