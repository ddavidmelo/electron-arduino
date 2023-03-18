<template>
  <q-layout view="lHh Lpr lFf">
    <q-header elevated>
      <q-toolbar>
        <q-btn flat dense round aria-label="Home" to="/" icon="list" />

        <q-toolbar-title>
          {{ this.$store.state.port.manufacturer }}
        </q-toolbar-title>

      </q-toolbar>
    </q-header>

    <q-page-container>
      <DeviceActions @command="writeCommand($event)" />


    </q-page-container>
  </q-layout>
  <q-dialog v-model="portClosed" position="bottom">
    <q-card style="width: 350px">

      <q-card-section class="row items-center no-wrap">
          <div class="text-weight-bold">Port is closed</div>
          <q-space />
          <q-btn flat dense round to="/" icon="arrow_back" />
      </q-card-section>
    </q-card>
  </q-dialog>
</template>

<script>
import DeviceActions from '../components/DeviceActions.vue'
const { SerialPort, ReadlineParser } = require('serialport')

var serialport;

export default {
  components: {
    DeviceActions
  },
  data() {
    return {
      timer: null,
      portClosed: false,
    }
  },
  methods: {
    writeCommand(command) {
      serialport.write(command, function (err) {
        if (err) {
          return console.log('Error on write: ', err.message)
        }
        console.log(command)
      })
    },
    checkPortStatus() {
      const parser = new ReadlineParser()
      serialport.pipe(parser)
      if (serialport.isOpen) {
        this.portClosed = false;
      } else {
        this.portClosed = true;
      }
    }
  },
  mounted() {
    console.log("open serial: ", this.$store.state.port.path);
    serialport = new SerialPort({ path: this.$store.state.port.path, baudRate: 9600 })

    this.timer = setInterval(() => {
      this.checkPortStatus()
    }, 500)
  },
  unmounted() {
    clearInterval(this.timer)
    serialport.close()
    console.log("close serial: ", this.$store.state.port.path);
  }
}
</script>
