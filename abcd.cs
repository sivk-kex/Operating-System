    using UnityEngine; 

    public class CarController : MonoBehaviour 

    {
    public GameObject playerCar; 
    public bool isGameOver;
    public float carSpeed;
    private float carTorque;  
    public GameObject instantiatedCar; 

    void Start(){ 
        
        instantiatedCar = Instantiate(playerCar, Vector3.zero, Quaternion.identity);
        carSpeed = 5f; 
        isGameOver = false; 

    }

    void Update(){ 

        if(!isGameOver){ 
            //instantiatedCar.transform.Translate(Vector3.forward,carSpeed,Time.deltaTime);     ->1 
            //instantiatedCar.transform.Translate(Vector3.forward, carSpeed, 0.1f);             ->2 
        }
    }


    void OnCollisionEnter(Collision other){ 
        if(other.gameObject.tag == "Obstacle"){ 
            Debug.Log("Game Over! Car crashed into obstacle."); 
            carSpeed =0; 
            isGameOver =true; 
        }
    }
    }