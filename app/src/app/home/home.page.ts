import { Component } from '@angular/core';

@Component({
  selector: 'app-home',
  templateUrl: 'home.page.html',
  styleUrls: ['home.page.scss'],
})
export class HomePage {

  public abierto9:boolean = false;
  public abiertoCa:boolean = false;
  public abiertoOx:boolean = false;
  public abiertoDng:boolean = false;
  public activos:boolean = false;

  constructor() {}

  abrir9()
  {
    if(this.abierto9 == true)
    {
      this.abierto9 = false;
    }
    else
    {
      this.abierto9 = true;
    }
  }

  abrirCa()
  {
    if(this.abiertoCa == true)
    {
      this.abiertoCa = false;
    }
    else
    {
      this.abiertoCa = true;
    }
  }

  abrirOx()
  {
    if(this.abiertoOx == true)
    {
      this.abiertoOx = false;
    }
    else
    {
      this.abiertoOx = true;
    }
  }

  abrirDng()
  {
    if(this.abiertoDng == true)
    {
      this.abiertoDng = false;
    }
    else
    {
      this.abiertoDng = true;
    }
  }


}
