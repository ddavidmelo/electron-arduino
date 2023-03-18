<template>
  <q-page class="flex flex-center">

    <q-list bordered padding class="rounded-borders" style="width: 350px; margin: 10px;">
      <div v-if="noDevices">
        Zero Devices Connected
      </div>
      <q-item v-for="port in serialports" :key="port.path" class="q-my-sm" clickable v-ripple @click="serialWrite(port)">
        <q-item-section avatar>
          <q-avatar icon="memory" color="blue" text-color="white" />
        </q-item-section>

        <q-item-section>
          <q-item-label>{{ port.manufacturer }}</q-item-label>
          <q-item-label caption lines="1">{{ port.path }}</q-item-label>
        </q-item-section>
      </q-item>
    </q-list>

  </q-page>
</template>

<style></style>

<script>
const { SerialPort } = require('serialport')

const serialports = []

export default {
  data() {
    return {
      serialports,
      noDevices: false,
      name: 'HelloWorld'
    }
  },
  methods: {
    async listSerialPorts() {
      await SerialPort.list().then((ports, err) => {
        if (err != null || err == undefined) {
          let devices = [];
          for (const device of ports) {
            if (device.productId != undefined && device.vendorId != undefined) {
              devices.push(device);
            }
          }
          if(devices.length == 0) {
            this.noDevices = true;
          } else {
            this.noDevices = false;
          }
          this.serialports = devices;
          console.log('ports: ', ports);
        }
      })
    },
    serialWrite(port) {
      this.$store.commit('setPort', port);
      this.$router.push({
        name: "device"
      });
    },
  },
  async mounted() {
    this.listSerialPorts()
  },
}
</script>
